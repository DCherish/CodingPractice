#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

struct cctvinfo
{
	int row;
	int col;
	int type;
};

int N, M;

int room[8][8];
bool visited[8][8];
cctvinfo cctv[8];

int mincnt = INT_MAX;

int rotation[6] = { NULL, 4, 2, 4, 4, 1 };

int cctv_cnt = 0;

void copy_room(int from[8][8], int to[8][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			to[i][j] = from[i][j];
		}
	}
}

void update(int dir, cctvinfo cctv)
{
	dir %= 4;

	if (dir == 0) // 悼率
	{
		for (int i = cctv.col + 1; i < M; i++)
		{
			if (room[cctv.row][i] == 6) break;
			room[cctv.row][i] = -1;
		}
	}
	else if (dir == 1) // 合率
	{
		for (int i = cctv.row - 1; i >= 0; i--)
		{
			if (room[i][cctv.col] == 6) break;
			room[i][cctv.col] = -1;
		}
	}
	else if (dir == 2) // 辑率
	{
		for (int i = cctv.col - 1; i >= 0; i--)
		{
			if (room[cctv.row][i] == 6) break;
			room[cctv.row][i] = -1;
		}
	}
	else if (dir == 3) // 巢率
	{
		for (int i = cctv.row + 1; i < N; i++)
		{
			if (room[i][cctv.col] == 6) break;
			room[i][cctv.col] = -1;
		}
	}
}

void DFS(int cnt)
{
	if (cnt == cctv_cnt)
	{
		int answer = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (room[i][j] == 0)
				{
					answer++;
				}
			}
		}

		mincnt = min(mincnt, answer);

		return;
	}

	int backup[8][8];
	int type = cctv[cnt].type;

	for (int dir = 0; dir < rotation[type]; dir++)
	{
		copy_room(room, backup);

		if (type == 1)
		{
			update(dir, cctv[cnt]);
		}
		else if (type == 2)
		{
			update(dir, cctv[cnt]);
			update(dir + 2, cctv[cnt]);
		}
		else if (type == 3)
		{
			update(dir, cctv[cnt]);
			update(dir + 1, cctv[cnt]);
		}
		else if (type == 4)
		{
			update(dir, cctv[cnt]);
			update(dir + 1, cctv[cnt]);
			update(dir + 2, cctv[cnt]);
		}
		else
		{
			update(dir, cctv[cnt]);
			update(dir + 1, cctv[cnt]);
			update(dir + 2, cctv[cnt]);
			update(dir + 3, cctv[cnt]);
		}

		DFS(cnt + 1);

		copy_room(backup, room);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> room[i][j];

			if (room[i][j] >= 1 && room[i][j] <= 5)
			{
				cctv[cctv_cnt].row = i;
				cctv[cctv_cnt].col = j;
				cctv[cctv_cnt].type = room[i][j];

				cctv_cnt++;
			}
		}
	}

	DFS(0);

	cout << mincnt << "\n";

	return 0;
}