#include <iostream>
#include <stack>

using namespace std;

int M, N;
int map[501][501];
int cnt[501][501];
bool visited[501][501];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

class pnt
{
public:
	int x;
	int y;
};

int DFS(int x, int y)
{
	if (x == M && y == N)
	{
		return 1;
	}

	if (visited[x][y] == true)
	{
		return cnt[x][y];
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= 0 || ny <= 0 || nx > M || ny > N) continue;
		if (map[nx][ny] >= map[x][y]) continue;

		cnt[x][y] += DFS(nx, ny);
	}

	return cnt[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << DFS(1, 1) << "\n";

	return 0;
}