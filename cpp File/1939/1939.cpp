#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct info
{
	int dst;
	int cost;
};

int N, M, A, B, C, F, T;
int maxcost;

vector<info> node[100001];
bool visited[100001];

bool BFS(int cost)
{
	queue<int> Q;
	Q.push(F);
	visited[F] = true;

	while (!Q.empty())
	{
		int cf = Q.front();
		Q.pop();

		if (cf == T) return true;

		for (int i = 0; i < node[cf].size(); i++)
		{
			int nf = node[cf][i].dst;
			int nc = node[cf][i].cost;

			if (visited[nf] == true) continue;
			if (cost <= nc)
			{
				visited[nf] = true;
				Q.push(nf);
			}
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		node[A].push_back({ B, C });
		node[B].push_back({ A, C });

		maxcost = max(maxcost, C);
	}

	cin >> F >> T;

	int start = 0;
	int end = maxcost;

	while (start <= end)
	{
		fill(visited, visited + N + 1, false); // Á¶½É

		int mid = (start + end) / 2;

		if (BFS(mid) == true) start = mid + 1;
		else end = mid - 1;
	}

	cout << end << "\n";

	return 0;
}