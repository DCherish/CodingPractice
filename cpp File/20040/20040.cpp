#include <iostream>

using namespace std;

int n, m, x, y, ans;
bool state = false;

int parent[500000];
int noderank[500000];

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

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		noderank[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;

		if (Find(x) == Find(y) && state == false)
		{
			state = true;
			ans = i + 1;
		}

		Union(x, y);
	}

	cout << ans << "\n";

	return 0;
}