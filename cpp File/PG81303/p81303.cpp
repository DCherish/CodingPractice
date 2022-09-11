#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
	int data;
	Node *prev;
	Node *next;

	Node(int d)
	{
		data = d;
		prev = NULL;
		next = NULL;
	}
};

struct LinkedList
{
	Node *head;
	Node *tail;

	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void Insert(int d);
	Node *Erase(Node *node);
	void Restore(Node *node);
};

void LinkedList::Insert(int d)
{
	if (head == NULL)
	{
		Node *newnode = new Node(d);
		head = newnode;
		tail = newnode;
	}
	else
	{
		Node *newnode = new Node(d);
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
}

Node *LinkedList::Erase(Node *node)
{
	if (node == head)
	{
		head = node->next;
		head->prev = NULL;
		return node->next;
	}
	else if (node == tail)
	{
		tail = node->prev;
		tail->next = NULL;
		return node->prev;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		return node->next;
	}
}

void LinkedList::Restore(Node *node)
{
	if (node->prev == NULL)
	{
		head = node;
		node->next->prev = node;
	}
	else if (node->next == NULL)
	{
		tail = node;
		node->prev->next = node;
	}
	else
	{
		node->prev->next = node;
		node->next->prev = node;
	}
}

stack<Node*> Delete;
LinkedList *List;

string solve(int n, int k, vector<string> cmd)
{
	Node *pnt = List->head;

	for (int i = 0; i < k; i++)
    {
        pnt = pnt->next;
    }

	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i][0] == 'U')
		{
			string sx = cmd[i].substr(2);
			int x = stoi(sx);

			for (int i = 0; i < x; i++)
            {
                pnt = pnt->prev;
            }
		}
		else if (cmd[i][0] == 'D')
		{
			string sx = cmd[i].substr(2);
			int x = stoi(sx);

			for (int i = 0; i < x; i++)
            {
                pnt = pnt->next;
            }
		}
		else if (cmd[i][0] == 'C')
		{
			Delete.push(pnt);
			pnt = List->Erase(pnt);
		}
		else if (cmd[i][0] == 'Z')
		{
			Node *Z = Delete.top();
			Delete.pop();
			List->Restore(Z);
		}
	}

	string result = "";

	for (int i = 0; i < n; i++)
    {
        result += 'O';
    }

	while (!Delete.empty())
	{
		Node *temp = Delete.top();
		Delete.pop();

		int idx = temp->data;
		result[idx] = 'X';
	}

	return result;
}

string solution(int n, int k, vector<string> cmd)
{
	string answer = "";

	List = new LinkedList();

	for (int i = 0; i < n; i++)
	{
		List->Insert(i);
	}

	answer = solve(n, k, cmd);

	return answer;
}