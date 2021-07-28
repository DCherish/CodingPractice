#include <iostream>
#include <vector>

using namespace std;

int N, M, num;
bool state = true;

int parent[201];
int noderank[201];

vector<int> plan;

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		noderank[i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> num;

			if (num == 1)
			{
				if (Find(i) != Find(j))
				{
					Union(i, j);
				}
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		plan.push_back(num);
	}

	for (int i = 0; i < M - 1; i++)
	{
		int from = plan[i];
		int to = plan[i + 1];

		if (Find(from) != Find(to))
		{
			state = false;
			break;
		}
	}

	if (state == true)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}

	return 0;
}