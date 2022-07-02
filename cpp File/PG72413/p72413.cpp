#include <string>
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
    bool operator()(info n1, info n2)
    {
        return n1.weight > n2.weight;
    }
};

vector<info> node[201];

int dist[3][201]; // 0 s, 1 a, 2 b

void dijkstra(int idx, int val)
{
    priority_queue<info, vector<info>, cmp> PQ;

    PQ.push({val, 0});

    while(!PQ.empty())
    {
        int num = PQ.top().num;
        int weight = PQ.top().weight;
        PQ.pop();

        if (dist[idx][num] != INT_MAX) continue;
        dist[idx][num] = weight;

        for (int i = 0; i < node[num].size(); i++)
        {
            if (dist[idx][node[num][i].num] != INT_MAX) continue;
            PQ.push({node[num][i].num, weight + node[num][i].weight});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INT_MAX;

    for (int i = 0; i < fares.size(); i++)
    {
        int from = fares[i][0];
        int to = fares[i][1];
        int weight = fares[i][2];

        node[from].push_back({to, weight});
        node[to].push_back({from, weight});
    }

    for (int i = 0; i < 3; i++)
    {
        fill(&dist[i][0], &dist[i][n + 1], INT_MAX);
    }

    dijkstra(0, s);
    dijkstra(1, a);
    dijkstra(2, b);

    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }

    return answer;
}