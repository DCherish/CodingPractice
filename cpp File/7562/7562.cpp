#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct info
{
	int x;
	int y;
	int cost;
};

int T;
int L, cx, cy, gx, gy;

bool visited[300][300];

vector<int> ans;

int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int BFS(int x, int y)
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

		if (cx == gx && cy == gy)
		{
			return cc;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= L || ny >= L) continue;
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

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> L;

		cin >> cx >> cy;
		cin >> gx >> gy;

		memset(visited, false, sizeof(visited));

		int result = BFS(cx, cy);

		ans.push_back(result);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}