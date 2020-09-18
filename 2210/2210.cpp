#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int matrix[5][5];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

map<string, int> info;

void DFS(int x, int y, int cnt, string s)
{
	if (cnt == 6)
	{
		if (info.count(s) == 0)
		{
			info[s] = 1;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

		DFS(nx, ny, cnt + 1, s + to_string(matrix[nx][ny]));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			DFS(i, j, 0, "");
		}
	}

	cout << info.size() << "\n";

	return 0;
}