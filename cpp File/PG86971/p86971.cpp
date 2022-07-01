#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits.h>

using namespace std;

int answer = INT_MAX;

struct pnt
{
    int x;
    int y;
};

vector<int> edge[101];
pnt except[101];

int groupCnt = 0;
int visitCnt[2];

bool visited[101];

bool exceptCheck(int num, int next, int idx)
{
    int from = except[idx].x;
    int to = except[idx].y;
    
    if ((from == num && to == next) || (to == num && from == next))
    {
        return true;
    }
    
    return false;
}

void DFS(int num, int idx)
{
    visited[num] = true;
    visitCnt[groupCnt]++;
    
    for (int i = 0; i < edge[num].size(); i++)
    {
        int next = edge[num][i];
        
        if (visited[next]) continue;
        if (exceptCheck(num, next, idx)) continue;
        
        DFS(next, idx);
    }
}

int solution(int n, vector<vector<int>> wires)
{
    for (int i = 0; i < wires.size(); i++)
    {
        edge[wires[i][0]].push_back(wires[i][1]);
        edge[wires[i][1]].push_back(wires[i][0]);
        
        except[i].x = wires[i][0];
        except[i].y = wires[i][1];
    }
    
    for (int i = 0; i < wires.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[j]) continue;
            
            DFS(j, i);
            groupCnt++;
        }
        
        if (groupCnt == 2)
        {
            answer = min(answer, abs(visitCnt[0] - visitCnt[1]));
        }
        
        groupCnt = 0;
        
        memset(visitCnt, 0, sizeof(visitCnt));
        memset(visited, false, sizeof(visited));
    }
    
    return answer;
}