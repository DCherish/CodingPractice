#include <iostream>
#include <vector>
#include <queue>
#define MAX 16

using namespace std;

vector<int> node[50001];
int parent[50001][MAX];
int depth[50001];

vector<int> answer;

queue<int> Q;

int N, M, u, v;

int LCA(int u, int v)
{
	if (depth[u] > depth[v]) swap(u, v);

	int diff = depth[v] - depth[u];

	int idx = 0;

	while (diff > 0)
	{
		if (diff % 2 == 1)
		{
			v = parent[v][idx];
		}

		idx++;

		diff /= 2;
	}

	if (u != v)
	{
		for (int i = MAX - 1; i >= 0; i--)
		{
			if (parent[u][i] != parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}

		u = parent[u][0];
	}

	return u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		depth[i] = -1;
	}

	depth[1] = 1;

	Q.push(1);

	while (!Q.empty())
	{
		int temp = Q.front();
		Q.pop();

		for (int i = 0; i < node[temp].size(); i++)
		{
			if (depth[node[temp][i]] != -1) continue;

			depth[node[temp][i]] = depth[temp] + 1;
			parent[node[temp][i]][0] = temp;

			Q.push(node[temp][i]);
		}
	}

	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 2; j <= N; j++)
		{
			int k = parent[j][i];

			if (k != 0) parent[j][i + 1] = parent[k][i];
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		int result = LCA(u, v);

		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}