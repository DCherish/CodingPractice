#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct info
{
	int x;
	int y;
	int cost;
};

int N, M, ans;
char MAP[50][50];
bool visited[50][50];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y)
{
	queue<info> Q;

	Q.push({ x, y, 0 });
	visited[x][y] = true;

	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		int cc = Q.front().cost;
		Q.pop();

		ans = max(cc, ans);

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (MAP[nx][ny] == 'W') continue;
			if (visited[nx][ny] == true) continue;

			visited[nx][ny] = true;
			Q.push({ nx, ny, cc + 1 });
		}
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
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == 'W') continue;

			memset(visited, false, sizeof(visited));
			BFS(i, j);
		}
	}

	cout << ans << "\n";

	return 0;
}