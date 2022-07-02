#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	int num;
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

	PQ.push({1, 0});

	while (!PQ.empty())
	{
		int num = PQ.top().num;
		int weight = PQ.top().weight;
		PQ.pop();

		if (dist[num] != INT_MAX) continue;
		dist[num] = weight;

		for (int i = 0; i < node[num].size(); i++)
		{
			if (dist[node[num][i].num] != INT_MAX) continue;
			PQ.push({node[num][i].num, weight + node[num][i].weight});
		}
	}
}

int solution(int N, vector<vector<int>> road, int K)
{
	int answer = 0;

	for (int i = 0; i < road.size(); i++)
	{
		int from = road[i][0];
		int to = road[i][1];
		int weight = road[i][2];

		node[from].push_back({to, weight});
		node[to].push_back({from, weight});
	}

	fill(dist + 1, dist + N + 1, INT_MAX);

	dijkstra();

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] <= K) answer++;
	}

	return answer;
}