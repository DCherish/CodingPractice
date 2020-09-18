#include <iostream>
#include <algorithm>
#include <queue>
#define INF 999999999

using namespace std;

int N, M, X;

class node
{
public:
	int num;
	int weight;
};

int maxnum = 0;

int tempdist[10001];
int comedist[10001];
int godist[10001];

class cmp
{
public:
	bool operator()(node n1, node n2)
	{
		return n1.weight > n2.weight;
	}
};

vector<node> map[10001];

void dijkstra()
{
	priority_queue<node, vector<node>, cmp> pq;

	for( int i = 1 ; i <= N ; i++ )
	{
		if( i == X ) 
		{
			comedist[i] = 0;
			continue;
		}
		
		pq.push({i, 0});

		while(!pq.empty())
		{
			int c_n = pq.top().num;
			int c_w = pq.top().weight;
			pq.pop();

			if( tempdist[c_n] != INF ) continue;
			tempdist[c_n] = c_w;

			if( c_n == X )
			{
				comedist[i] = c_w;

				for( int i = 1 ; i <= N ; i++ )
				{
					tempdist[i] = INF;
				}
				
				while(!pq.empty()) pq.pop();
				break;
			}

			for( int i = 0 ; i < map[c_n].size() ; i++ )
			{
				if( tempdist[map[c_n][i].num] != INF ) continue;
				pq.push({map[c_n][i].num, c_w + map[c_n][i].weight});
			}
		}
	}

	pq.push({X, 0});

	while(!pq.empty())
	{
		int c_n = pq.top().num;
		int c_w = pq.top().weight;
		pq.pop();

		if( godist[c_n] != INF ) continue;
		godist[c_n] = c_w;

		for( int i = 0 ; i < map[c_n].size() ; i++ )
		{
			if( godist[map[c_n][i].num] != INF ) continue;
			pq.push({map[c_n][i].num, c_w + map[c_n][i].weight});
		}
	}

	for( int i = 1 ; i <= N ; i++ )
	{
		godist[i] = comedist[i] + godist[i];
		if( maxnum < godist[i] ) maxnum = godist[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;

	for( int i = 0 ; i < M ; i++ )
	{
		int u, v, w;
		cin >> u >> v >> w;

		map[u].push_back({v, w});
	}

	for( int i = 1 ; i <= N ; i++ )
	{
		tempdist[i] = INF;
		comedist[i] = INF;
		godist[i] = INF;
	}
	
	dijkstra();

	cout << maxnum << "\n";
	
	return 0;
}