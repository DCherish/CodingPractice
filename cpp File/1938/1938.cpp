#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct info
{
	int x;
	int y;
	int angle;
	int cnt;
};

struct pnt
{
	int x;
	int y;
};

int arr[50][50];
bool visited[50][50][2];

int N;
int cnt = 0;

string str;

queue<info> Q;

vector<pnt> B_pnt;
vector<pnt> E_pnt;

int rx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ry[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int b_angle;

bool check_shape(int x, int y, int angle)
{
	if (x == E_pnt[1].x && y == E_pnt[1].y)
	{
		if (angle == 0)
		{
			if (x == E_pnt[0].x && y - 1 == E_pnt[0].y
				&& x == E_pnt[2].x && y + 1 == E_pnt[2].y)
			{
				return true;
			}
			else return false;
		}
		else
		{
			if (x - 1 == E_pnt[0].x && y == E_pnt[0].y
				&& x + 1 == E_pnt[2].x && y == E_pnt[2].y)
			{
				return true;
			}
			else return false;
		}
	}
	else return false;
}

bool can_rotate(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int tx = x + rx[i];
		int ty = y + ry[i];

		if (tx < 0 || ty < 0 || tx >= N || ty >= N) return false;
		if (arr[tx][ty] == 1) return false;
	}

	return true;
}

void BFS()
{
	if (B_pnt[1].x - B_pnt[0].x == 0)
	{
		b_angle = 0; // 天
	}
	else b_angle = 1; // 太

	visited[B_pnt[1].x][B_pnt[1].y][b_angle] = true;
	Q.push({ B_pnt[1].x, B_pnt[1].y, b_angle, 0 });

	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		int ca = Q.front().angle;
		int cc = Q.front().cnt;

		Q.pop();

		if (check_shape(cx, cy, ca) == true)
		{
			cnt = cc;
			return;
		}

		if (ca == 0)
		{
			if (can_rotate(cx, cy) == true && visited[cx][cy][1] == false)
			{
				visited[cx][cy][1] = true;
				Q.push({ cx, cy, 1, cc + 1 });
			}
		}
		else
		{
			if (can_rotate(cx, cy) == true && visited[cx][cy][0] == false)
			{
				visited[cx][cy][0] = true;
				Q.push({ cx, cy, 0, cc + 1 });
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (ca == 0) // 天
			{
				if (nx < 0 || ny < 1 || nx >= N || ny >= N - 1) continue;
				if (arr[nx][ny] == 1 || visited[nx][ny][ca] == true) continue;

				if (arr[nx][ny - 1] == 0 && arr[nx][ny + 1] == 0)
				{
					visited[nx][ny][ca] = true;
					Q.push({ nx, ny, ca, cc + 1 });
				}
			}
			else // 太
			{
				if (nx < 1 || ny < 0 || nx >= N - 1 || ny >= N) continue;
				if (arr[nx][ny] == 1 || visited[nx][ny][ca] == true) continue;

				if (arr[nx - 1][ny] == 0 && arr[nx + 1][ny] == 0)
				{
					visited[nx][ny][ca] = true;
					Q.push({ nx, ny, ca, cc + 1 });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin.ignore(256, '\n');

	for (int i = 0; i < N; i++)
	{
		getline(cin, str);

		for (int j = 0; j < N; j++)
		{
			if (str[j] == 'B')
			{
				arr[i][j] = 0;
				B_pnt.push_back({ i, j });
			}
			else if (str[j] == '0')
			{
				arr[i][j] = 0;
			}
			else if (str[j] == '1')
			{
				arr[i][j] = 1;
			}
			else if (str[j] == 'E')
			{
				arr[i][j] = 0;
				E_pnt.push_back({ i, j });
			}
		}
	}

	BFS();

	cout << cnt << "\n";

	return 0;
}