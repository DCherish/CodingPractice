#include <iostream>

using namespace std;

int N, ans;
int MAP[500][500];

int cx, cy;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int xdx[4][10] = { {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {1, 1, 0, 0, 0, 0, -1, -1, -2, -1} };
int ydy[4][10] = { {1, 1, 0, 0, 0, 0, -1, -1, -2, -1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {-1, 1, -1, 1, -2, 2, -1, 1, 0, 0} };
int percent[9] = { 1, 1, 7, 7, 2, 2, 10, 10, 5 };

void spread_sand(int x, int y, int dir)
{
	int sand = MAP[x][y];
	int temp = sand;

	for (int i = 0; i < 9; i++)
	{
		int nx = x + xdx[dir][i];
		int ny = y + ydy[dir][i];
		int per = percent[i];

		int plus = (temp * per) / 100;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) ans += plus;
		else MAP[nx][ny] += plus;

		sand -= plus;
	}

	int nx = x + xdx[dir][9];
	int ny = y + ydy[dir][9];

	if (nx < 0 || nx >= N || ny < 0 || ny >= N) ans += sand;
	else MAP[nx][ny] += sand;

	MAP[x][y] = 0;
}

void do_move()
{
	int idx = 1;
	int t_idx = 1;
	int dir = 0;

	int mid = N / 2;

	cx = mid;
	cy = mid;

	bool state = false;

	while (true)
	{
		if (idx == N)
		{
			idx -= 1;
			state = true;
		}

		for (int i = 0; i < idx; i++)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (MAP[nx][ny] != 0) spread_sand(nx, ny, dir);

			cx = nx;
			cy = ny;
		}

		if (state == true) break;

		if (t_idx == 1) t_idx++;
		else
		{
			idx++;
			t_idx = 1;
		}

		dir++;

		if (dir == 4) dir = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	do_move();

	cout << ans << "\n";

	return 0;
}