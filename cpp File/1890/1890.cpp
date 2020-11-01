#include <iostream>

using namespace std;

int N;
int matrix[101][101];
long long cnt[101][101];
bool visited[101][101];

int dv[2] = {0, 1};
int dh[2] = {1, 0};

long long DFS(int x, int y)
{
	if (x == N && y == N)
	{
		return 1;
	}

	if (visited[x][y] == true)
	{
		return cnt[x][y];
	}

	visited[x][y] = true;

	for (int i = 0; i < 2; i++)
	{
		int nx = x + dv[i] * matrix[x][y];
		int ny = y + dh[i] * matrix[x][y];

		if (nx > N || ny > N) continue;

		cnt[x][y] += DFS(nx, ny);
	}

	return cnt[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << DFS(1, 1) << "\n";

	return 0;
}