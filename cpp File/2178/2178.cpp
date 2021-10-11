#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct pnt
{
	int x;
	int y;
	int cnt;
};

int N, M, result = INT_MAX;

char MAP[100][100];
bool visited[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pnt> Q;

void BFS(int x, int y)
{
	visited[x][y] = true;
	Q.push({ x, y, 1 });

	while (!Q.empty())
	{
		int qx = Q.front().x;
		int qy = Q.front().y;
		int qcnt = Q.front().cnt;
		Q.pop();

		if (qx == N - 1 && qy == M - 1)
		{
			result = min(result, qcnt);
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (MAP[nx][ny] == '0' || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			Q.push({ nx, ny, qcnt + 1 });
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
			visited[i][j] = false;
		}
	}

	BFS(0, 0);

	cout << result << "\n";

	return 0;
}