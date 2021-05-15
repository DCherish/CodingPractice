#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, V, E, a, b;

vector<int> node[20001];
vector<bool> answer;

int visited[20001];

void BFS(int idx)
{
	queue<int> Q;

	visited[idx] = 1;
	Q.push(idx);

	while (!Q.empty())
	{
		int num = Q.front();
		
		int temp = visited[num];
		int op_temp;

		if (temp == 1) op_temp = 2;
		else op_temp = 1;

		Q.pop();

		for (int i = 0; i < node[num].size(); i++)
		{
			if (visited[node[num][i]] == 0)
			{
				visited[node[num][i]] = op_temp;
				Q.push(node[num][i]);
			}
		}
	}
}

bool solve()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 0; j < node[i].size(); j++)
		{
			if (visited[i] == visited[node[i][j]]) return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;

		for (int j = 1; j <= V; j++)
		{
			node[j].clear();
			visited[j] = 0;
		}

		for (int j = 0; j < E; j++)
		{
			cin >> a >> b;

			node[a].push_back(b);
			node[b].push_back(a);
		}

		for (int j = 1; j <= V; j++)
		{
			if (visited[j] == 0)
			{
				BFS(j);
			}
		}

		bool result = solve();

		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == true)
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
	}

	return 0;
}