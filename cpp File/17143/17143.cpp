#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int idx;
	int x;
	int y;
	int speed;
	int dir;
	int size;
};

int R, C, M;
int r, c, s, d, z;

int answer = 0;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

vector<info> shark;
vector<int> MAP[100][100];

bool cmp(int a, int b)
{
	return shark[a].size > shark[b].size;
}

void catch_shark(int idx)
{
	for (int i = 0; i < R; i++)
	{
		if (MAP[i][idx].size() == 0) continue;
		else
		{
			answer += shark[MAP[i][idx][0]].size;
			shark[MAP[i][idx][0]].size = 0;
			MAP[i][idx].clear();
			break;
		}
	}
}

void move_shark()
{
	for (int i = 0; i < shark.size(); i++)
	{
		if (shark[i].size == 0) continue;
		int x = shark[i].x;
		int y = shark[i].y;
		MAP[x][y].clear();
	}

	for (int i = 0; i < shark.size(); i++)
	{
		if (shark[i].size == 0) continue;
		int x = shark[i].x;
		int y = shark[i].y;
		int dir = shark[i].dir;
		int speed = shark[i].speed;

		if (dir == 1 || dir == 2)
		{
			int rotate = (R - 1) * 2;

			if (speed >= rotate) speed %= rotate;

			for (int j = 0; j < speed; j++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0)
				{
					dir = 2;
					nx = nx + 2;
				}

				if (nx > R - 1)
				{
					dir = 1;
					nx = nx - 2;
				}

				x = nx;
				y = ny;
			}
		}
		else
		{
			int rotate = (C - 1) * 2;

			if (speed >= rotate) speed %= rotate;

			for (int j = 0; j < speed; j++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (ny < 0)
				{
					dir = 3;
					ny = ny + 2;
				}

				if (ny > C - 1)
				{
					dir = 4;
					ny = ny - 2;
				}
				x = nx;
				y = ny;
			}
		}

		shark[i].x = x;
		shark[i].y = y;
		shark[i].dir = dir;
		MAP[x][y].push_back(i);
	}
}

void kill_shark()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (MAP[i][j].size() > 1)
			{
				sort(MAP[i][j].begin(), MAP[i][j].end(), cmp);
				int idx = MAP[i][j][0];

				for (int k = 1; k < MAP[i][j].size(); k++)
				{
					shark[MAP[i][j][k]].size = 0;
					shark[MAP[i][j][k]].x = -1;
					shark[MAP[i][j][k]].y = -1;
				}
				MAP[i][j].clear();
				MAP[i][j].push_back(shark[idx].idx);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;

	if (M != 0)
	{
		for (int i = 0; i < M; i++)
		{
			cin >> r >> c >> s >> d >> z;

			shark.push_back({ i, r - 1, c - 1, s, d, z });
			MAP[r - 1][c - 1].push_back(i);
		}

		for (int i = 0; i < C; i++)
		{
			catch_shark(i);
			move_shark();
			kill_shark();
		}
	}

	cout << answer << "\n";

	return 0;
}