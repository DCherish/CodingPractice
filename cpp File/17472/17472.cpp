#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 10000

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

int N, M, answer;

char MAP[11][11];
int visited[11][11];

int parent[10];
int noderank[10];
int dist[10][10];

int idx = 1;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<info> vec;
vector<pnt> pos[101];

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

void DFS(int x, int y, int dir, int sz, int start, int end)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;

	if (MAP[nx][ny] == '0') DFS(nx, ny, dir, sz + 1, start, end);
	else
	{
		if (visited[nx][ny] == end)
		{
			if (sz > 1)
			{
				if (dist[start][end] > sz)
				{
					dist[start][end] = sz;
					dist[end][start] = sz;
				}
			}
		}

		return;
	}
}

void Search(int start, int end)
{
	for (int i = 0; i < pos[start].size(); i++)
	{
		int x = pos[start][i].x;
		int y = pos[start][i].y;

		for (int j = 0; j < 4; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (MAP[nx][ny] == '0')
			{
				DFS(x, y, j, 0, start, end);
			}
		}
	}
}

void BFS(int x, int y)
{
	visited[x][y] = idx;

	queue<pnt> Q;
	Q.push({ x, y });

	while (!Q.empty())
	{
		int qx = Q.front().x;
		int qy = Q.front().y;
		Q.pop();

		pos[idx].push_back({ qx, qy });

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visited[nx][ny] != 0) continue;
			if (MAP[nx][ny] == '0') continue;

			visited[nx][ny] = idx;
			Q.push({ nx, ny });
		}
	}
}

bool check()
{
	int x = parent[1];

	for (int i = 2; i < idx; i++)
	{
		int y = Find(i);

		if (x != y) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == '1' && visited[i][j] == 0)
			{
				BFS(i, j);
				idx++;
			}
		}
	}

	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < idx; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 1; i < idx; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			Search(i, j);

			if (dist[i][j] == INF) continue;

			vec.push_back({ i, j, dist[i][j] });
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 1; i < idx; i++)
	{
		parent[i] = i;
		noderank[i] = 0;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		int u = vec[i].from;
		int v = vec[i].to;
		int c = vec[i].cost;

		if (Find(u) == Find(v)) continue;

		Union(u, v);

		answer += c;
	}

	if (check()) cout << answer << "\n";
	else cout << "-1\n";

	return 0;
}