#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

int n, m;
int o, a, b;
int parent[1000001];
int noderank[1000001];

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

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
		noderank[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> o >> a >> b;

		if (o == 0)
		{
			Union(a, b);
		}
		else
		{
			if (Find(a) == Find(b))
			{
				answer.push_back("YES");
			}
			else
			{
				answer.push_back("NO");
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}