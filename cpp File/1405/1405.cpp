#include <iostream>
#include <algorithm>

using namespace std;

int N;
double percent[4]; // ep, wp, sp, np

bool visited[30][30];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

double DFS(int x, int y, int cnt)
{
	if (cnt == N) return 1.0;

	double result = 0.0;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visited[nx][ny] == true) continue;

		result += percent[i] * DFS(nx, ny, cnt + 1);
	}

	visited[x][y] = false;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		cin >> percent[i];

		percent[i] /= 100.0;
	}

	double answer = DFS(15, 15, 0);

	cout.precision(10);

	cout << fixed << answer << "\n";

	return 0;
}