#include <iostream>
#include <stack>

using namespace std;

struct info
{
	int x;
	int y;
	int dir;
};

int N, M;
int row, col, dir, fdir, temp;

int max_cnt = 0;

int arr[51][51];
bool visited[51][51];

stack<info> S;

int dir_x[4] = { -1, 0, 1, 0 }; // 0123 북동남서
int dir_y[4] = { 0, 1, 0, -1 }; // 0123 북동남서

int dx[4] = { -1, 0, 1, 0 }; // 북서남동 반시계방향
int dy[4] = { 0, -1, 0, 1 }; // 북서남동 반시계방향

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void solve()
{
	S.push({ row, col, dir });

	while (!S.empty())
	{
		bool state = true;

		int tx = S.top().x;
		int ty = S.top().y;
		int tdir = S.top().dir;

		S.pop();

		for (int i = 0; i < 4; i++)
		{
			if (dir_x[tdir] == dx[i] && dir_y[tdir] == dy[i])
			{
				fdir = i;
				break;
			}
		}

		for (int i = 1; i <= 4; i++)
		{
			temp = fdir + i;

			if (temp >= 4) temp -= 4;

			int nx = tx + dx[temp];
			int ny = ty + dy[temp];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] == true || arr[nx][ny] == 1) continue;

			visited[nx][ny] = true;
			max_cnt++;

			for (int j = 0; j < 4; j++)
			{
				if (dx[temp] == dir_x[j] && dy[temp] == dir_y[j])
				{
					temp = j;
					break;
				}
			}

			S.push({ nx, ny, temp });
			state = false;
			break;
		}

		if (state == true)
		{
			int qx = tx - dx[temp];
			int qy = ty - dy[temp];

			if (arr[qx][qy] != 1)
			{
				for (int i = 0; i < 4; i++)
				{
					if (dx[temp] == dir_x[i] && dy[temp] == dir_y[i])
					{
						temp = i;
						break;
					}
				}

				S.push({ qx, qy, temp });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	cin >> row >> col >> dir;

	init();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	visited[row][col] = true;
	max_cnt++;

	solve();

	cout << max_cnt << "\n";

	return 0;
}