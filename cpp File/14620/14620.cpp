#include <iostream>
#include <algorithm>
#include <deque>
#include <limits.h>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N;
int arr[10][10];
bool visited[10][10];

bool flower_leaf[10][10];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int answer = INT_MAX;

deque<pnt> DQ;

bool isValid()
{
	deque<pnt> temp = DQ;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			flower_leaf[i][j] = false;
		}
	}

	while (!temp.empty())
	{
		int x = temp.front().x;
		int y = temp.front().y;
		temp.pop_front();

		if (flower_leaf[x][y] == true)
		{
			return false;
		}

		flower_leaf[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (flower_leaf[nx][ny] == true) return false;

			flower_leaf[nx][ny] = true;
		}
	}

	return true;
}

void DFS(int x, int y, int depth)
{
	if (depth == 3)
	{
		if (isValid() == true)
		{
			int result = 0;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (flower_leaf[i][j] == true)
					{
						result += arr[i][j];
					}
				}
			}

			answer = min(answer, result);
		}

		return;
	}

	for (int i = x; i < N - 1; i++)
	{
		for (int j = y; j < N - 1; j++)
		{
			if (visited[i][j] == true) continue;

			visited[i][j] = true;
			DQ.push_back({ i, j });
			DFS(i, j + 1, depth + 1);
			DQ.pop_back();
			visited[i][j] = false;
		}
		y = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(1, 1, 0);

	cout << answer << "\n";

	return 0;
}