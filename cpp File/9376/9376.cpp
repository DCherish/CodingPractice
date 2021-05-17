#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits.h>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int T, h, w, result, sum;
int arr[104][104];
int dist[104][104][3];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

deque<pnt> DQ;
vector<pnt> prisoner;
vector<int> answer;

void BFS()
{
	for (int i = 0; i < 3; i++)
	{
		int cx = prisoner[i].x;
		int cy = prisoner[i].y;

		dist[cx][cy][i] = 0;
		DQ.push_back({ cx, cy });

		while (!DQ.empty())
		{
			int qx = DQ.front().x;
			int qy = DQ.front().y;
			DQ.pop_front();

			for (int j = 0; j < 4; j++)
			{
				int nx = qx + dx[j];
				int ny = qy + dy[j];

				if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w + 2) continue;
				if (dist[nx][ny][i] != -1) continue;

				if (arr[nx][ny] == 0)
				{
					dist[nx][ny][i] = dist[qx][qy][i];
					DQ.push_front({ nx, ny });
				}
				else if (arr[nx][ny] == 1)
				{
					dist[nx][ny][i] = dist[qx][qy][i] + 1;
					DQ.push_back({ nx, ny });
				}
			}
		}
	}
}

void init()
{
	prisoner.clear();

	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				dist[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i <= h + 1; i++)
	{
		for (int j = 0; j <= w + 1; j++)
		{
			arr[i][j] = 0;
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
		cin >> h >> w;

		init();

		prisoner.push_back({ 0, 0 });

		for (int j = 0; j <= w + 1; j++)
		{
			arr[0][j] = 0;
			arr[h + 1][j] = 0;
		}

		for (int j = 1; j <= h; j++)
		{
			arr[j][0] = 0;

			for (int k = 1; k <= w; k++)
			{
				char c;
				cin >> c;

				if (c == '*')
				{
					arr[j][k] = -1;
				}
				else if (c == '#')
				{
					arr[j][k] = 1;
				}
				else if (c == '.')
				{
					arr[j][k] = 0;
				}
				else if (c == '$')
				{
					arr[j][k] = 0;
					prisoner.push_back({ j, k });
				}
			}

			arr[j][w + 1] = 0;
		}

		BFS();

		result = INT_MAX;

		for (int j = 0; j <= h + 1; j++)
		{
			for (int k = 0; k <= w + 1; k++)
			{
				if (arr[j][k] == -1) continue;

				sum = dist[j][k][0] + dist[j][k][1] + dist[j][k][2];

				if (sum == -3) continue; // 접근 불가 영역

				if (arr[j][k] == 1) sum -= 2;

				result = min(result, sum);
			}
		}

		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}