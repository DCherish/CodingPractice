#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M, H, a, b;

bool visited[11][31];

int answer = INT_MAX;

bool goDown()
{
	for (int i = 1; i <= N; i++)
	{
		int c_num = i;

		for (int j = 1; j <= H; j++)
		{
			if (visited[c_num][j] == true) c_num += 1;
			else if (visited[c_num - 1][j] == true) c_num -= 1;
		}

		if (c_num != i) return false;
	}

	return true;
}

void DFS(int idx, int cnt)
{
	if (cnt >= 4) return;

	if (goDown() == true)
	{
		answer = min(answer, cnt);
		return;
	}

	for (int i = idx; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (visited[j][i] == true) continue;
			if (visited[j - 1][i] == true) continue;
			if (visited[j + 1][i] == true) continue;

			visited[j][i] = true;
			DFS(i, cnt + 1);
			visited[j][i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		visited[b][a] = true;
	}

	DFS(1, 0);

	if (answer == INT_MAX)
	{
		answer = -1;
	}

	cout << answer << "\n";

	return 0;
}