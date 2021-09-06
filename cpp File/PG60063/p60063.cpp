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

int solution(vector<vector<int>> board)
{
	int answer = 0;

	N = board.size();

	memset(visited, false, sizeof(visited));

	Q.push({ 0, 1, 2, 0 });
	visited[0][0][3] = true;
	visited[0][1][2] = true;

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

				if (board[nx][ny] == 0 && visited[nx][ny][rvs(dir)] == false && visited[xx][yy][dir] == false)
				{
					visited[nx][ny][rvs(dir)] = true;
					visited[xx][yy][dir] = true;
					Q.push({ xx, yy, dir, cnt + 1 });
				}
			}
			else if (i == rvs(dir))
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				if (board[nx][ny] == 0 && visited[nx][ny][dir] == false && visited[x][y][rvs(dir)] == false)
				{
					visited[nx][ny][dir] = true;
					visited[x][y][rvs(dir)] = true;
					Q.push({ nx, ny, dir, cnt + 1 });
				}
			}
			else
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				int nxx = xx + dx[i];
				int nyy = yy + dy[i];

				if (nx < 0 || ny < 0 || nxx < 0 || nyy < 0 || nx >= N || ny >= N || nxx >= N || nyy >= N) continue;

				if (board[nx][ny] == 0 && board[nxx][nyy] == 0 && visited[nx][ny][dir] == false && visited[nxx][nyy][rvs(dir)] == false)
				{
					visited[nx][ny][dir] = true;
					visited[nxx][nyy][rvs(dir)] = true;
					Q.push({ nx, ny, dir, cnt + 1 });
				}
			}
		}

		if (dir == 0 || dir == 1)
		{
			int cy = y - 1;
			int cyy = yy - 1;

			if (cy >= 0 && cyy >= 0 && cy < N && cyy < N)
			{
				if (board[x][cy] == 0 && board[xx][cyy] == 0)
				{
					if (visited[x][y][2] == false && visited[x][cy][3] == false)
					{
						visited[x][y][2] = true;
						visited[x][cy][3] = true;
						Q.push({ x, y, 2, cnt + 1 });
					}

					if (visited[xx][yy][2] == false && visited[xx][cyy][3] == false)
					{
						visited[xx][yy][2] = true;
						visited[xx][cyy][3] = true;
						Q.push({ xx, cyy, 3, cnt + 1 });
					}
				}
			}

			cy = y + 1;
			cyy = yy + 1;

			if (cy >= 0 && cyy >= 0 && cy < N && cyy < N)
			{
				if (board[x][cy] == 0 && board[xx][cyy] == 0)
				{
					if (visited[x][y][3] == false && visited[x][cy][2] == false)
					{
						visited[x][y][3] = true;
						visited[x][cy][2] = true;
						Q.push({ x, y, 3, cnt + 1 });
					}

					if (visited[xx][yy][3] == false && visited[xx][cyy][2] == false)
					{
						visited[xx][yy][3] = true;
						visited[xx][cyy][2] = true;
						Q.push({ xx, cyy, 2, cnt + 1 });
					}
				}
			}
		}
		else
		{
			int cx = x - 1;
			int cxx = xx - 1;

			if (cx >= 0 && cxx >= 0 && cx < N && cxx < N)
			{
				if (board[cx][y] == 0 && board[cxx][yy] == 0)
				{
					if (visited[x][y][0] == false && visited[cx][y][1] == false)
					{
						visited[x][y][0] = true;
						visited[cx][y][1] = true;
						Q.push({ x, y, 0, cnt + 1 });
					}

					if (visited[xx][yy][0] == false && visited[cxx][yy][1] == false)
					{
						visited[xx][yy][0] = true;
						visited[cxx][yy][1] = true;
						Q.push({ cxx, yy, 1, cnt + 1 });
					}
				}
			}

			cx = x + 1;
			cxx = xx + 1;

			if (cx >= 0 && cxx >= 0 && cx < N && cxx < N)
			{
				if (board[cx][y] == 0 && board[cxx][yy] == 0)
				{
					if (visited[x][y][1] == false && visited[cx][y][0] == false)
					{
						visited[x][y][1] = true;
						visited[cx][y][0] = true;
						Q.push({ x, y, 1, cnt + 1 });
					}

					if (visited[xx][yy][1] == false && visited[cxx][yy][0] == false)
					{
						visited[xx][yy][1] = true;
						visited[cxx][yy][0] = true;
						Q.push({ cxx, yy, 0, cnt + 1 });
					}
				}
			}
		}
	}

	return answer;
}