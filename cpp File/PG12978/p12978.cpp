#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	int idx;
	int weight;
};

class cmp
{
public:
	bool operator()(info a, info b)
	{
		return a.weight > b.weight;
	}
};

vector<info> node[51];
int dist[51];

void dijkstra()
{
	priority_queue<info, vector<info>, cmp> PQ;

	PQ.push({ 1, 0 });

	while (!PQ.empty())
	{
		int idx = PQ.top().idx;
		int weight = PQ.top().weight;
		PQ.pop();

		if (dist[idx] != INT_MAX) continue;
		dist[idx] = weight;

		for (int i = 0; i < node[idx].size(); i++)
		{
			if (dist[node[idx][i].idx] != INT_MAX) continue;
			PQ.push({ node[idx][i].idx, weight + node[idx][i].weight });
		}
	}
}

int solution(int N, vector<vector<int>> road, int K)
{
	int answer = 0;

	for (int i = 0; i < road.size(); i++)
	{
		int a = road[i][0];
		int b = road[i][1];
		int weight = road[i][2];

		node[a].push_back({ b, weight });
		node[b].push_back({ a, weight });
	}

	fill(dist + 1, dist + N + 1, INT_MAX);

	dijkstra();

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] <= K) answer++;
	}

	return answer;
}