#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct node
{
    int num;
    int weight;
};

class cmp
{
public:
    bool operator()(node n1, node n2)
    {
        return n1.weight > n2.weight;
    }
};

vector<node> map[201];

int dist[3][201]; // 0 s, 1 a, 2 b

void Dijkstra(int idx, int val)
{
    priority_queue<node, vector<node>, cmp> PQ;

    PQ.push({val, 0});

    while(!PQ.empty())
    {
        int cnum = PQ.top().num;
        int cweight = PQ.top().weight;
        PQ.pop();

        if (dist[idx][cnum] != INT_MAX) continue;
        dist[idx][cnum] = cweight;

        for (int i = 0; i < map[cnum].size(); i++)
        {
            if (dist[idx][map[cnum][i].num] != INT_MAX) continue;
            PQ.push({map[cnum][i].num, cweight + map[cnum][i].weight});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;

    for (int i = 0; i < fares.size(); i++)
    {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];

        map[c].push_back({d, f});
        map[d].push_back({c, f});
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    Dijkstra(0, s);
    Dijkstra(1, a);
    Dijkstra(2, b);

    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }

    return answer;
}