#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N, M, a, b, ans;
int MAP[50][50];
bool visited[50][50];

vector<pnt> cloud;
vector<pnt> cmd;

int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void do_move(int idx)
{
	int dir = cmd[idx].x;
	int speed = cmd[idx].y;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < cloud.size(); i++)
	{
		int x = cloud[i].x;
		int y = cloud[i].y;

		int nx = x;
		int ny = y;

		for (int j = 0; j < speed; j++)
		{
			nx += dx[dir];
			ny += dy[dir];

			if (nx < 0) nx = N - 1;
			if (nx >= N) nx = 0;

			if (ny < 0) ny = N - 1;
			if (ny >= N) ny = 0;
		}

		cloud[i].x = nx;
		cloud[i].y = ny;
	}

	for (int i = 0; i < cloud.size(); i++)
	{
		int x = cloud[i].x;
		int y = cloud[i].y;
		visited[x][y] = true;
	}
}

void do_rain()
{
	for (int i = 0; i < cloud.size(); i++)
	{
		int x = cloud[i].x;
		int y = cloud[i].y;
		MAP[x][y]++;
	}
}

void do_water_copy()
{
	for (int i = 0; i < cloud.size(); i++)
	{
		int x = cloud[i].x;
		int y = cloud[i].y;

		int cnt = 0;

		for (int j = 2; j <= 8; j += 2)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (MAP[nx][ny] >= 1) cnt++;
		}

		MAP[x][y] += cnt;
	}
}

void do_make_cloud()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == true) continue;
			if (MAP[i][j] < 2) continue;
			MAP[i][j] -= 2;
			cloud.push_back({ i, j });
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < cloud.size(); i++)
	{
		int x = cloud[i].x;
		int y = cloud[i].y;
		visited[x][y] = true;
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
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cmd.push_back({ a, b });
	}

	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });
	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N - 1, 1 });

	for (int i = 0; i < M; i++)
	{
		do_move(i);
		do_rain();
		do_water_copy();

		cloud.clear();

		do_make_cloud();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans += MAP[i][j];
		}
	}

	cout << ans << "\n";

	return 0;
}