#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int MAP[50][50];
int DP[50][50];
bool visited[50][50];

int N, M, ans;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int DFS(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M || MAP[x][y] == -1) return 0;

	if (visited[x][y] == true)
	{
		cout << -1 << "\n";
		exit(0);
	}

	if (DP[x][y] != -1) return DP[x][y];

	visited[x][y] = true;
	DP[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + (MAP[x][y] * dx[i]);
		int ny = y + (MAP[x][y] * dy[i]);

		DP[x][y] = max(DP[x][y], DFS(nx, ny) + 1);
	}

	visited[x][y] = false;

	return DP[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	cin.ignore(256, '\n');

	for (int i = 0; i < N; i++)
	{
		string str;

		getline(cin, str);

		for (int j = 0; j < M; j++)
		{
			if (str[j] != 'H')
			{
				MAP[i][j] = str[j] - '0';
			}
			else
			{
				MAP[i][j] = -1;
			}
		}
	}

	memset(DP, -1, sizeof(DP));

	cout << DFS(0, 0) << "\n";

	return 0;
}