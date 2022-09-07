#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct pnt
{
    int x;
    int y;
    int cnt;
};

char MAP[5][5];
bool visited[5][5];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool BFS(int x, int y)
{
    queue<pnt> Q;
    Q.push({ x, y, 0 });
    visited[x][y] = true;
    
    while (!Q.empty())
    {
        int qx = Q.front().x;
        int qy = Q.front().y;
        int qcnt = Q.front().cnt;
        Q.pop();
        
        if (qcnt == 2) continue;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visited[nx][ny] || MAP[nx][ny] == 'X') continue;
            
            if (MAP[nx][ny] == 'P') return false;
            
            Q.push({ nx, ny, qcnt + 1 });
            visited[nx][ny] = true;
        }
    }
    
    return true;
}

bool check()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (MAP[i][j] == 'P')
            {
                // fill(&visited[0][0], &visited[4][5], false);
                memset(visited, false, sizeof(visited));
                if (!BFS(i, j)) return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    
    for (auto vec : places)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                MAP[i][j] = vec[i][j];
            }
        }
        
        if (check()) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}