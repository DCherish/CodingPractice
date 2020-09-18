#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Elem
{
public:
	int from;
	int to;
	int weight;
};

vector<Elem> arr;

int N, M;
int parent[1001];

int mincost = 0;

bool cmp(Elem a, Elem b)
{
	return a.weight < b.weight;
}

int Find(int k)
{
	if( parent[k] == k ) return k;
	else return parent[k] = Find(parent[k]);
}

void Union(int x, int y)
{
	int a = Find(x);
	int b = Find(y);

	if( a <= b ) parent[b] = a;
	else parent[a] = b;
}

void kruskal()
{
	for( int i = 0 ; i < arr.size() ; i++ )
	{
		int c_f = arr[i].from;
		int c_t = arr[i].to;
		int c_w = arr[i].weight;

		if( Find(c_f) == Find(c_t) ) continue; // update & find

		Union(c_f, c_t); // connect
		mincost = mincost + c_w;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> M;

	for( int i = 0 ; i < M ; i++ )
	{
		int u, v, w;

		cin >> u >> v >> w;

		arr.push_back({u, v, w});
	}

	sort(arr.begin(), arr.end(), cmp);

	for( int i = 1 ; i <= N ; i++ )
	{
		parent[i] = i;
	}

	kruskal();

	cout << mincost << "\n";

	return 0;
}