#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N, M;
int virus_pnt = 0;
int empty_pnt = 0;
int MAP[50][50];
int visited[50][50];

int result = INT_MAX;

vector<int> sel;
vector<pnt> vec;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS()
{
	queue<pnt> Q;

	int infect_pnt = 0;
	int final_cost = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = -1;
		}
	}

	for (int i = 0; i < M; i++)
	{
		Q.push({ vec[sel[i]].x, vec[sel[i]].y });
		visited[vec[sel[i]].x][vec[sel[i]].y] = 0;
	}

	while (!Q.empty())
	{
		int qx = Q.front().x;
		int qy = Q.front().y;

		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] != -1 || MAP[nx][ny] == 1) continue;

			visited[nx][ny] = visited[qx][qy] + 1;

			if (MAP[nx][ny] == 0)
			{
				infect_pnt++;
				final_cost = visited[nx][ny];
			}

			Q.push({ nx, ny });
		}
	}

	if (infect_pnt == empty_pnt)
	{
		result = min(result, final_cost);
	}
}

void solve(int idx, int depth)
{
	if (depth == M)
	{
		BFS();

		return;
	}

	for (int i = idx; i < virus_pnt; i++)
	{
		sel.push_back(i);
		solve(i + 1, depth + 1);
		sel.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];

			if (MAP[i][j] == 2)
			{
				vec.push_back({ i, j });
				virus_pnt++;
			}
			else if (MAP[i][j] == 0)
			{
				empty_pnt++;
			}
		}
	}

	solve(0, 0);

	if (result == INT_MAX)
	{
		result = -1;
	}

	cout << result << "\n";

	return 0;
}