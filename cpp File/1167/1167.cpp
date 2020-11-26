#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class info
{
public:
	int num;
	int cost;
};

int V, f, t, c;
vector<info> vec[100001];
int visited[100001];
int maxcost = 0;
int maxnode;

void DFS(int idx)
{
	stack<int> S;

	visited[idx] = 0;
	S.push(idx);

	while (!S.empty())
	{
		int temp = S.top();
		S.pop();

		for (int i = 0; i < vec[temp].size(); i++)
		{
			if (visited[vec[temp][i].num] == -1)
			{
				visited[vec[temp][i].num] = vec[temp][i].cost + visited[temp];
				S.push(vec[temp][i].num);

				if (visited[vec[temp][i].num] > maxcost)
				{
					maxcost = visited[vec[temp][i].num];
					maxnode = vec[temp][i].num;
				}
			}
		}
	}
}

void init()
{
	maxcost = 0;

	for (int i = 1; i <= V; i++)
	{
		visited[i] = -1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V;

	init();

	for (int i = 0; i < V; i++)
	{
		cin >> f;

		for (;;)
		{
			cin >> t;

			if (t != -1)
			{
				cin >> c;

				vec[f].push_back({ t, c });
				vec[t].push_back({ f, c });
			}
			else break;
		}
	}

	DFS(1);

	init();

	DFS(maxnode);

	cout << maxcost << "\n";

	return 0;
}