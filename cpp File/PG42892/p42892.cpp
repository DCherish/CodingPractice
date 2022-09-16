#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x;
    int y;
    int idx;
    Node *left;
    Node *right;
};

Node *root;

vector<int> prevec;
vector<int> postvec;

bool cmp(Node a, Node b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }
    else return a.y > b.y;
}

void postOrder(Node *parent)
{
    if (parent == NULL) return;
    postOrder(parent->left);
    postOrder(parent->right);
    postvec.push_back(parent->idx);
}

void preOrder(Node *parent)
{
    if (parent == NULL) return;
    prevec.push_back(parent->idx);
    preOrder(parent->left);
    preOrder(parent->right);
}

void makeBinaryTree(Node *parent, Node *child)
{
    if (child->x < parent->x)
    {
        if (parent->left == NULL)
        {
            parent->left = child;
            return;
        }
        else makeBinaryTree(parent->left, child);
    }
    else
    {
        if (parent->right == NULL)
        {
            parent->right = child;
            return;
        }
        else makeBinaryTree(parent->right, child);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    
    vector<Node> vec;
    
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int idx = i + 1;
        vec.push_back({ x, y, idx, NULL, NULL });
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    root = &vec[0];
    
    for (int i = 1; i < vec.size(); i++)
    {
        makeBinaryTree(root, &vec[i]);
    }
    
    preOrder(root);
    postOrder(root);
    
    answer.push_back(prevec);
    answer.push_back(postvec);
    
    return answer;
}