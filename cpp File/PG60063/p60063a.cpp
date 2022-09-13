#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct info
{
	int x;
	int y;
	int dir;
	int cnt;
};

int N;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool visited[101][101][4];

queue<info> Q;

int rvs(int idx)
{
	if (idx == 0) return 1;
	else if (idx == 1) return 0;
	else if (idx == 2) return 3;
	else if (idx == 3) return 2;
}

bool check(int idx, int x, int y, int xx, int yy, vector<vector<int>> &board)
{
    int nx = x + dx[idx];
    int ny = y + dy[idx];
    
    int nxx = xx + dx[idx];
    int nyy = yy + dy[idx];
    
    if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
    if (nxx < 0 || nyy < 0 || nxx >= N || nyy >= N) return false;
    
    if (board[nx][ny] == 1 || board[nxx][nyy] == 1) return false;
    
    return true;
}

int solution(vector<vector<int>> board)
{
	int answer = 0;

	N = board.size();

	visited[0][0][3] = true;
	visited[0][1][2] = true;
    
    Q.push({ 0, 1, 2, 0 });

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int dir = Q.front().dir;
		int cnt = Q.front().cnt;

		int xx = x + dx[dir];
		int yy = y + dy[dir];

		Q.pop();

		if ((x == N - 1 && y == N - 1) || (xx == N - 1 && yy == N - 1))
		{
			answer = cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			if (i == dir)
			{
				int nx = xx + dx[i];
				int ny = yy + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                
                if (board[nx][ny] == 1) continue;
				if (visited[nx][ny][rvs(dir)] || visited[xx][yy][dir]) continue;
				
                visited[nx][ny][rvs(dir)] = true;
				visited[xx][yy][dir] = true;
				
                Q.push({ xx, yy, dir, cnt + 1 });
			}
			else if (i == rvs(dir))
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				if (board[nx][ny] == 1) continue;
                if (visited[nx][ny][dir] || visited[x][y][rvs(dir)]) continue;
                
				visited[nx][ny][dir] = true;
				visited[x][y][rvs(dir)] = true;
                
				Q.push({ nx, ny, dir, cnt + 1 });
			}
			else
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				int nxx = xx + dx[i];
				int nyy = yy + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (nxx < 0 || nyy < 0 || nxx >= N || nyy >= N) continue;

				if (board[nx][ny] == 1 || board[nxx][nyy] == 1) continue;
                if (visited[nx][ny][dir] || visited[nxx][nyy][rvs(dir)]) continue;
                
				visited[nx][ny][dir] = true;
				visited[nxx][nyy][rvs(dir)] = true;
                
				Q.push({ nx, ny, dir, cnt + 1 });
			}
		}
        
        for (int i = 0; i < 4; i++)
        {
            if (check(i, x, y, xx, yy, board))
            {
                if (!visited[x][y][i] && !visited[x + dx[i]][y + dy[i]][rvs(i)])
                {
                    visited[x][y][i] = true;
                    visited[x + dx[i]][y + dy[i]][rvs(i)] = true;
                    Q.push({ x, y, i, cnt + 1 });
                }
                    
                if (!visited[xx][yy][i] && !visited[xx + dx[i]][yy + dy[i]][rvs(i)])
                {
                    visited[xx][yy][i] = true;
                    visited[xx + dx[i]][yy + dy[i]][rvs(i)] = true;
                    Q.push({ xx, yy, i, cnt + 1 });
                }    
            }
        }
	}

	return answer;
}

