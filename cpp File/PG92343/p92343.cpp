#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> node[20];
vector<int> state;
bool visited[20][20][20];

int maxSheep;

void solve(int idx, int scnt, int wcnt)
{
    if (idx == 0) maxSheep = max(maxSheep, scnt);
    
    for (int i = 0; i < node[idx].size(); i++)
    {
        int next = node[idx][i];
        
        if (state[next] == 0)
        {
            if (!visited[next][scnt + 1][wcnt])
            {
                visited[next][scnt + 1][wcnt] = true;
                state[next] = -1;
                solve(next, scnt + 1, wcnt);
                state[next] = 0;
                visited[next][scnt + 1][wcnt] = false;
            }
        }
        else if (state[next] == 1)
        {
            if (!visited[next][scnt][wcnt + 1] && scnt > wcnt + 1)
            {
                visited[next][scnt][wcnt + 1] = true;
                state[next] = -1;
                solve(next, scnt, wcnt + 1);
                state[next] = 1;
                visited[next][scnt][wcnt + 1] = false;
            }
        }
        else
        {
            if (!visited[next][scnt][wcnt])
            {
                visited[next][scnt][wcnt] = true;
                solve(next, scnt, wcnt);
                visited[next][scnt][wcnt] = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    int answer = 0;
    
    for (int i = 0; i < edges.size(); i++)
    {
        node[edges[i][0]].push_back(edges[i][1]);
        node[edges[i][1]].push_back(edges[i][0]);
    }
    
    state = info;
    state[0] = -1;
    visited[0][1][0] = true;
    solve(0, 1, 0);
    
    answer = maxSheep;
    
    return answer;
}