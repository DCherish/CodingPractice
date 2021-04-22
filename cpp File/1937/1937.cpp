#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[500][500];
int dp[500][500];
int maxcnt = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int DFS(int x, int y)
{
	if (dp[x][y] == 0)
	{
		dp[x][y] = 1;

		int temp = 0;

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (arr[x][y] < arr[nx][ny])
			{
				temp = max(temp, DFS(nx, ny));
			}
		}

		dp[x][y] += temp;
	}

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];

			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxcnt = max(maxcnt, DFS(i, j));
		}
	}

	cout << maxcnt << "\n";

	return 0;
}