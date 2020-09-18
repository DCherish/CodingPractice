#include <iostream>
#include <algorithm>
#include <queue>

#define INF 999999999

using namespace std;

class Elem
{
public:
	int src;
	int num;
	int dist;
};

class Answer
{
public:
	int ans;
	int wer;
};

class cmp
{
public:
	bool operator()(Elem a, Elem b)
	{
		return a.dist > b.dist;
	}
};

int N, M;
int A, B, C;

vector<Answer> answer;
vector<Elem> arr[1000001];
int dist[1001];

void dijkstra()
{
	priority_queue <Elem, vector<Elem>, cmp> pq;

	pq.push({0, 1, 0});

	while(!pq.empty())
	{
		int c_src = pq.top().src;
		int c_num = pq.top().num;
		int c_dist = pq.top().dist;

		pq.pop();

		if( dist[c_num] != INF ) continue;
		dist[c_num] = c_dist;

		if( c_src != 0 ) answer.push_back({c_src, c_num});

		for( int i = 0 ; i < arr[c_num].size() ; i++ )
		{
			if( dist[arr[c_num][i].num] != INF ) continue;
			pq.push({c_num, arr[c_num][i].num, c_dist + arr[c_num][i].dist});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for( int i = 1 ; i <= N ; i++ )
	{
		dist[i] = INF;
	}

	for( int i = 0 ; i < M ; i++ )
	{
		cin >> A >> B >> C;

		arr[A].push_back({A, B, C});
		arr[B].push_back({B, A, C});
	}

	dijkstra();

	cout << answer.size() << "\n";

	for( int i = 0 ; i < answer.size() ; i++ )
	{
		cout << answer[i].ans << " " << answer[i].wer << "\n";
	}

	return 0;
}