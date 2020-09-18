#include <iostream>
#include <algorithm>
#include <queue>
#define INF -1

using namespace std;

int V, E, K;

class node
{
public:
	int n;
	int w;
};

vector<node> map[20001];

int dist[20001];

class cmp
{
public:
	bool operator()(node n1, node n2)
	{
		return n1.w > n2.w;
	}
}; // minheap

void dijkstra()
{
	priority_queue<node, vector<node>, cmp> pq;

	pq.push({K, 0});

	while(!pq.empty())
	{
		int c_n = pq.top().n;
		int c_w = pq.top().w;
		pq.pop();

		if( dist[c_n] != INF ) continue;
		dist[c_n] = c_w;

		for( int i = 0 ; i < map[c_n].size() ; i++ )
		{
			if( dist[map[c_n][i].n] != INF ) continue;
			pq.push({map[c_n][i].n, c_w + map[c_n][i].w});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;

	for( int i = 0 ; i < E ; i++ )
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		map[u].push_back({v, w});
	}

	for( int i = 1 ; i <= V ; i++ )
	{
		dist[i] = INF;
	}

	dijkstra();

	for( int i = 1 ; i <= V ; i++ )
	{
		if( dist[i] == INF )
		{
			cout << "INF\n" ;
		}else
		{
			cout << dist[i] << "\n" ;
		}
	}
}