#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, from, to;
vector<int> vec[100001];
int visited[100001];
queue<int> Q;

void BFS()
{
	visited[1] = 1;

	Q.push(1);

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		for (int i = 0; i < vec[idx].size(); i++)
		{
			if (visited[vec[idx][i]] == -1)
			{
				visited[vec[idx][i]] = idx;
				Q.push(vec[idx][i]);
			}
		}
	}
}

void init()
{
	for (int i = 1; i <= N; i++)
	{
		visited[i] = -1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	init();

	for (int i = 0; i < N - 1; i++)
	{
		cin >> from >> to;

		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	BFS();

	for (int i = 2; i <= N; i++)
	{
		cout << visited[i] << "\n";
	}

	return 0;
}