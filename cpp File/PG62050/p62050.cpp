#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct pnt
{
	int x;
	int y;
};

struct info
{
	int from;
	int to;
	int cost;
};

int N, H, idx = 1;
int MAP[301][301];
int visited[301][301];
int parent[90001];
int noderank[90001];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<info> vec;

int Find(int k)
{
	if (parent[k] == k) return k;
	else return parent[k] = Find(parent[k]);
}

void Union(int x, int y)
{
	int a = Find(x);
	int b = Find(y);

	if (noderank[a] < noderank[b])
	{
		parent[a] = b;
	}
	else if (noderank[a] == noderank[b])
	{
		if (a < b)
		{
			parent[b] = a;
			noderank[a]++;
		}
		else
		{
			parent[a] = b;
			noderank[b]++;
		}
	}
	else
	{
		parent[b] = a;
	}
}

bool cmp(info a, info b)
{
	if (a.cost == b.cost)
	{
		if (a.from == b.from)
		{
			return a.to < b.to;
		}
		else return a.from < b.from;
	}
	else return a.cost < b.cost;
}

void BFS(int x, int y)
{
	queue<pnt> Q;
	Q.push({ x, y });

	visited[x][y] = idx;

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
			if (visited[nx][ny] != 0) continue;
			if (abs(MAP[qx][qy] - MAP[nx][ny]) > H) continue;

			visited[nx][ny] = idx;
			Q.push({ nx, ny });
		}
	}
}

int solution(vector<vector<int>> land, int height)
{
	int answer = 0;

	N = land.size();
	H = height;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = land[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				BFS(i, j);
				idx++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int u = visited[i][j];

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				int v = visited[nx][ny];

				if (u == v) continue;

				int u_value = MAP[i][j];
				int v_value = MAP[nx][ny];

				vec.push_back({ u, v, abs(u_value - v_value) });
			}
		}
	}

	for (int i = 1; i < idx; i++)
	{
		parent[i] = i;
		noderank[i] = 0;
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		int u = vec[i].from;
		int v = vec[i].to;
		int c = vec[i].cost;

		if (Find(u) == Find(v)) continue;

		Union(u, v);

		answer += c;
	}

	return answer;
}