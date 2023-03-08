#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt;
int u, v;

vector<int> node[1001];
bool visited[1001];

void BFS(int idx)
{
	queue<int> Q;

    visited[idx] = true;
	Q.push(idx);

	while (!Q.empty())
	{
		int num = Q.front();
		Q.pop();

        int sz = node[num].size();

		for (int k = 0; k < sz; k++)
		{
			if (!visited[node[num][k]])
			{
				visited[node[num][k]] = true;
				Q.push(node[num][k]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			BFS(i);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}