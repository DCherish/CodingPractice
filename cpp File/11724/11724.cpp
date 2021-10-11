#include <iostream>
#include <queue>

using namespace std;

int N, M, cnt;

int matrix[1000][1000];
bool visited[1000];

void BFS(int idx)
{
	queue<int> Q;

	Q.push(idx);

	while (!Q.empty())
	{
		int visit = Q.front();
		Q.pop();

		for (int k = 0; k < N; k++)
		{
			if (matrix[visit][k] == 1 && visited[k] == false)
			{
				visited[k] = true;
				Q.push(k);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int u = 0;
	int v = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;

		matrix[u - 1][v - 1] = 1;
		matrix[v - 1][u - 1] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			BFS(i);
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}