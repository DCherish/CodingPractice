#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
int A, B, C;

int parent[10001];
int noderank[10001];

int mincost = 0;

class Elem
{
public:
	int from;
	int to;
	int weight;
};

vector<Elem> arr;

bool cmp(Elem e1, Elem e2)
{
	return e1.weight < e2.weight;
}

int Find(int k)
{
	if (parent[k] == k) return k;
	else return parent[k] = Find(parent[k]);
}

void Union(int x, int y)
{
	int a = Find(x);
	int b = Find(y);

	if (a == b) return;

	if (noderank[a] < noderank[b])
	{
		parent[a] = b;
	}
	else if (noderank[a] == noderank[b])
	{
		if( a <= b )
		{
			parent[b] = a;
			noderank[a]++;
		}
		else
		{
			parent[a] = b;
			noderank[b]++;
		}
	}else
	{
		parent[b] = a;
	}
}

void kruskal()
{
	for (int i = 0; i < arr.size(); i++)
	{
		int c_f = arr[i].from;
		int c_t = arr[i].to;
		int c_w = arr[i].weight;

		if (Find(c_f) == Find(c_t)) continue;

		Union(c_f, c_t);
		mincost = mincost + c_w;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		cin >> A >> B >> C;

		arr.push_back({ A, B, C });
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
		noderank[i] = 0;
	}

	kruskal();

	cout << mincost << "\n";

	return 0;
}