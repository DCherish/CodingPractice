#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N, Q;
int MAP[70][70];
int L[1001];
int idx;
int maxcnt = 0;

stack<pnt> S;
bool visited[70][70];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void do_move(int x, int y, int depth)
{
	if (depth == idx)
	{
		vector<int> temp[70];

		int temp_idx = 0;

		for (int i = y; i < y + depth; i++)
		{
			for (int j = x + depth - 1; j >= x; j--)
			{
				temp[temp_idx].push_back(MAP[j][i]);
			}
			temp_idx++;
		}

		for (int i = 0; i < temp_idx; i++)
		{
			for (int j = 0; j < temp_idx; j++)
			{
				MAP[x + i][y + j] = temp[i][j];
			}
		}

		return;
	}

	int h_depth = depth / 2;

	do_move(x, y, h_depth);
	do_move(x, y + h_depth, h_depth);
	do_move(x + h_depth, y, h_depth);
	do_move(x + h_depth, y + h_depth, h_depth);
}

void do_remove()
{
	vector<pnt> temp;

	int p_N = pow(2, N);

	for (int i = 1; i <= p_N; i++)
	{
		for (int j = 1; j <= p_N; j++)
		{
			if (MAP[i][j] == 0) continue;
			else
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 1 || nx > p_N || ny < 1 || ny > p_N) continue;
					if (MAP[nx][ny] > 0) cnt++;
				}

				if (cnt < 3) temp.push_back({ i, j }); // 즉시 MAP[i][j]-- 하면 다른 MAP[x][y] 영향을 줌
			}
		}
	}

	for (int i = 0; i < temp.size(); i++) // 따라서 vector에 저장하여 후에 얼음을 녹이는 것으로 수정
	{
		int x = temp[i].x;
		int y = temp[i].y;

		MAP[x][y]--;
	}
}

void count_ice()
{
	int p_N = pow(2, N);

	int total_ice = 0;

	for (int i = 1; i <= p_N; i++)
	{
		for (int j = 1; j <= p_N; j++)
		{
			if (MAP[i][j] == 0) continue;

			total_ice += MAP[i][j];
		}
	}

	cout << total_ice << "\n";
}

void DFS(int x, int y)
{
	int cnt = 1;
	int p_N = pow(2, N);

	visited[x][y] = true;
	S.push({ x, y });

	while (!S.empty())
	{
		int sx = S.top().x;
		int sy = S.top().y;
		S.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];

			if (nx < 1 || nx > p_N || ny < 1 || ny > p_N) continue;
			if (visited[nx][ny] == true || MAP[nx][ny] <= 0) continue;
			else
			{
				cnt++;

				visited[nx][ny] = true;
				S.push({ nx, ny });
			}
		}
	}

	maxcnt = max(maxcnt, cnt);
}

void count_ice_group()
{
	memset(visited, false, sizeof(visited));

	int p_N = pow(2, N);

	for (int i = 1; i <= p_N; i++)
	{
		for (int j = 1; j <= p_N; j++)
		{
			if (MAP[i][j] == 0 || visited[i][j] == true) continue;

			DFS(i, j);
		}
	}

	cout << maxcnt << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;

	int p_N = pow(2, N);

	for (int i = 1; i <= p_N; i++)
	{
		for (int j = 1; j <= p_N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 1; i <= Q; i++)
	{
		cin >> L[i];
	}

	for (int i = 1; i <= Q; i++)
	{
		idx = pow(2, L[i]);

		do_move(1, 1, p_N);
		do_remove();
	}

	count_ice();
	count_ice_group();

	return 0;
}