#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int col;

vector<int> vec;

void solve(int N, int depth, int idx, int visited, vector<vector<string>> &relation)
{
    if (N == depth)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == (visited & vec[i])) return;
        }
        
        unordered_set<string> uset;
        
        for (int i = 0; i < relation.size(); i++)
        {
            string str = "";
            
            for (int j = 0; j < col; j++)
            {
                if ((visited & (1 << j)) != 0)
                {
                    str += relation[i][j];
                    str += '/';
                }
            }
            
            if (uset.count(str) != 0) return;
            
            uset.insert(str);
        }
        
        vec.push_back(visited);
        
        return;
    }
    
    for (int i = idx; i < col; i++)
    {
        solve(N, depth + 1, i + 1, visited + (1 << i), relation);
    }
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    
    col = relation[0].size();
    
    for (int i = 1; i <= col; i++)
    {
        solve(i, 0, 0, 0, relation);
    }
    
    answer = vec.size();
    
    return answer;
}