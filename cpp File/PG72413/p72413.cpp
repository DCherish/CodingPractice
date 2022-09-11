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
    bool operator()(info a, info b)
    {
        return a.weight > b.weight;
    }
};

vector<info> node[201];

int dist[3][201];

void dijkstra(int idx, int num)
{
    priority_queue<info, vector<info>, cmp> pq;
    
    pq.push({ num, 0 });
    
    while (!pq.empty())
    {
        int n = pq.top().num;
        int w = pq.top().weight;
        pq.pop();
        
        if (dist[idx][n] != INT_MAX) continue;
        dist[idx][n] = w;
        
        for (int i = 0; i < node[n].size(); i++)
        {
            if (dist[idx][node[n][i].num] != INT_MAX) continue;
            pq.push({ node[n][i].num, w + node[n][i].weight });
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
        
        node[from].push_back({ to, weight });
        node[to].push_back({ from, weight });
    }
    
    fill(&dist[0][0], &dist[2][n + 1], INT_MAX);
    
    dijkstra(0, s);
    dijkstra(1, a);
    dijkstra(2, b);
    
    for (int i = 1; i <= n; i++)
    {
        answer = min(answer, dist[0][i] + dist[1][i] + dist[2][i]);
    }
    
    return answer;
}