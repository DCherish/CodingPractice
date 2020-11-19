#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, F, T;

vector<int> connect[101];
queue<int> Q;
bool visited[101];

int cnt = 0;

void BFS()
{
	visited[1] = true;
	Q.push(1);

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		for (int i = 0; i < connect[idx].size(); i++)
		{
			if (visited[connect[idx][i]] == false)
			{
				visited[connect[idx][i]] = true;
				Q.push(connect[idx][i]);
				cnt++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> F >> T;

		connect[F].push_back(T);
		connect[T].push_back(F);
	}

	BFS();

	cout << cnt << "\n";

	return 0;
}