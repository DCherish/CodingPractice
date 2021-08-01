#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct info
{
	int x;
	int y;
	int cnt;
};

struct pnt
{
	int x;
	int y;
};

int R, C, cnt;
char MAP[50][50];
bool visited[50][50];

int W_MAP[50][50];

int s_x, s_y;
int e_x, e_y;

queue<pnt> W_Q;
queue<info> Q;

bool state = false;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void cal_water()
{
	while (!W_Q.empty())
	{
		int qx = W_Q.front().x;
		int qy = W_Q.front().y;
		W_Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

			if (MAP[nx][ny] == '.')
			{
				if (W_MAP[nx][ny] == 999)
				{
					W_MAP[nx][ny] = W_MAP[qx][qy] + 1;
					W_Q.push({ nx, ny });
				}
			}
		}
	}
}

void cal_move()
{
	Q.push({ s_x, s_y, 0 });
	visited[s_x][s_y] = true;

	while (!Q.empty())
	{
		int qx = Q.front().x;
		int qy = Q.front().y;
		int qcnt = Q.front().cnt;
		Q.pop();

		if (qx == e_x && qy == e_y)
		{
			state = true;
			cnt = qcnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

			if (visited[nx][ny] == true || MAP[nx][ny] == 'X') continue;

			if (W_MAP[nx][ny] > qcnt + 1)
			{
				visited[nx][ny] = true;
				Q.push({ nx, ny, qcnt + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(visited, false, sizeof(visited));

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			W_MAP[i][j] = 999;

			cin >> MAP[i][j];

			if (MAP[i][j] == 'S')
			{
				s_x = i;
				s_y = j;
			}
			else if (MAP[i][j] == 'D')
			{
				e_x = i;
				e_y = j;
			}
			else if (MAP[i][j] == '*')
			{
				W_MAP[i][j] = 0;
				W_Q.push({ i, j });
			}
		}
	}

	cal_water();
	cal_move();

	if (state == true)
	{
		cout << cnt << "\n";
	}
	else
	{
		cout << "KAKTUS" << "\n";
	}

	return 0;
}