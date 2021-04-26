#include <iostream>
#include <queue>
#include <deque>

using namespace std;

struct pnt
{
	int tx;
	int ty;
};

struct info
{
	int time;
	char dir;
};

int N, K, row, col, L, X;
char C;

int t_time = 0;

int idx_time;
char idx_dir;

int arr[101][101];

deque<pnt> DQ;
queue<info> mQ;

int dx[4] = { 0, 1, 0, -1 }; // ©Л го аб ╩С
int dy[4] = { 1, 0, -1, 0 }; // ©Л го аб ╩С

int change_dir(int p_dir, char c_dir)
{
	if (c_dir == 'L')
	{
		p_dir -= 1;
	}
	else
	{
		p_dir += 1;
	}

	if (p_dir == -1) p_dir = 3;
	else if (p_dir == 4) p_dir = 0;

	return p_dir;
}

void Dummy(int x, int y, int d)
{
	int nx = x + dx[d];
	int ny = y + dy[d];

	t_time++;

	if (nx < 1 || ny < 1 || nx > N || ny > N || arr[nx][ny] == 2)
	{
		cout << t_time << "\n";
		exit(0);
	}

	if (arr[nx][ny] != 1)
	{
		arr[DQ.back().tx][DQ.back().ty] = 0;
		DQ.pop_back();
	}

	arr[nx][ny] = 2;
	DQ.push_front({ nx, ny });

	if (t_time == idx_time)
	{
		d = change_dir(d, idx_dir);

		if (!mQ.empty())
		{
			idx_time = mQ.front().time;
			idx_dir = mQ.front().dir;

			mQ.pop();
		}
	}

	Dummy(nx, ny, d);
}

void init()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 0;
		}
	}

	while (!mQ.empty())
	{
		mQ.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	init();

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> row >> col;

		arr[row][col] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;

		mQ.push({ X, C });
	}

	idx_time = mQ.front().time;
	idx_dir = mQ.front().dir;
	mQ.pop();

	arr[1][1] = 2;
	DQ.push_front({ 1, 1 });
	Dummy(1, 1, 0);

	return 0;
}