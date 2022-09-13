#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pnt
{
    int x;
    int y;
};

struct info
{
    pnt p1;
    pnt p2;
    int cnt;
    bool shape; // horizontal: false, vertical: true;
};

bool visited[101][101][101][101];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<info> Q;

int N;

bool check(int idx, pnt p1, pnt p2, vector<vector<int>> &board)
{
    int nx1 = p1.x + dx[idx];
    int ny1 = p1.y + dy[idx];
    
    int nx2 = p2.x + dx[idx];
    int ny2 = p2.y + dy[idx];
    
    if (nx1 < 0 || ny1 < 0 || nx1 >= N || ny1 >= N) return false;
    if (nx2 < 0 || ny2 < 0 || nx2 >= N || ny2 >= N) return false;
            
    if (board[nx1][ny1] == 1 || board[nx2][ny2] == 1) return false;
    
    return true;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    N = board.size();
    
    visited[0][0][0][1] = true;
    
    Q.push({ { 0, 0 }, { 0, 1 }, 0, false });
    
    while (!Q.empty())
    {
        pnt p1 = Q.front().p1;
        pnt p2 = Q.front().p2;
        int cnt = Q.front().cnt;
        bool shape = Q.front().shape;
        Q.pop();
        
        if (p2.x == N - 1 && p2.y == N - 1)
        {
            return cnt;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx1 = p1.x + dx[i];
            int ny1 = p1.y + dy[i];
            
            int nx2 = p2.x + dx[i];
            int ny2 = p2.y + dy[i];
            
            if (nx1 < 0 || ny1 < 0 || nx1 >= N || ny1 >= N) continue;
            if (nx2 < 0 || ny2 < 0 || nx2 >= N || ny2 >= N) continue;
            
            if (board[nx1][ny1] == 1 || board[nx2][ny2] == 1) continue;
            if (visited[nx1][ny1][nx2][ny2]) continue;
            
            visited[nx1][ny1][nx2][ny2] = true;
            Q.push({ { nx1, ny1 }, { nx2, ny2 }, cnt + 1, shape });
        }
        
        if (!shape)
        {
            for (int i = 0; i < 2; i++)
            {
                if (check(i, p1, p2, board))
                {
                    if (i == 0)
                    {
                        if (!visited[p1.x - 1][p1.y][p1.x][p1.y])
                        {
                            visited[p1.x - 1][p1.y][p1.x][p1.y] = true;
                            Q.push({ { p1.x - 1, p1.y }, { p1.x, p1.y }, cnt + 1, true });
                        }
                        
                        if (!visited[p2.x - 1][p2.y][p2.x][p2.y])
                        {
                            visited[p2.x - 1][p2.y][p2.x][p2.y] = true;
                            Q.push({ { p2.x - 1, p2.y }, { p2.x, p2.y }, cnt + 1, true });
                        }
                    }
                    else
                    {
                        if (!visited[p1.x][p1.y][p1.x + 1][p1.y])
                        {
                            visited[p1.x][p1.y][p1.x + 1][p1.y] = true;
                            Q.push({ { p1.x, p1.y }, { p1.x + 1, p1.y }, cnt + 1, true });
                        }
                        
                        if (!visited[p2.x][p2.y][p2.x + 1][p2.y])
                        {
                            visited[p2.x][p2.y][p2.x + 1][p2.y] = true;
                            Q.push({ { p2.x, p2.y }, { p2.x + 1, p2.y }, cnt + 1, true });
                        }
                    }
                }
            }
        }
        else
        {
            for (int i = 2; i < 4; i++)
            {
                if (check(i, p1, p2, board))
                {
                    if (i == 2)
                    {
                        if (!visited[p1.x][p1.y - 1][p1.x][p1.y])
                        {
                            visited[p1.x][p1.y - 1][p1.x][p1.y] = true;
                            Q.push({ { p1.x, p1.y - 1 }, { p1.x, p1.y }, cnt + 1, false });
                        }
                        
                        if (!visited[p2.x][p2.y][p2.x][p2.y - 1])
                        {
                            visited[p2.x][p2.y][p2.x][p2.y - 1] = true;
                            Q.push({ { p2.x, p2.y }, { p2.x, p2.y - 1 }, cnt + 1, false });
                        }
                    }
                    else
                    {
                        if (!visited[p1.x][p1.y][p1.x][p1.y + 1])
                        {
                            visited[p1.x][p1.y][p1.x][p1.y + 1] = true;
                            Q.push({ { p1.x, p1.y }, { p1.x, p1.y + 1 }, cnt + 1, false });
                        }
                        
                        if (!visited[p2.x][p2.y][p2.x][p2.y + 1])
                        {
                            visited[p2.x][p2.y][p2.x][p2.y + 1] = true;
                            Q.push({ { p2.x, p2.y }, { p2.x, p2.y + 1 }, cnt + 1, false });
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}