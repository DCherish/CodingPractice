#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

int info[3600][2];
int dist[60][60];

int get_dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void update_dist(int x, int y, int n, int idx)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = min(dist[i][j], get_dist(i, j, x, y));
        }
    }

    info[idx][0] = x;
    info[idx][1] = y;
}

vector<int> solution(int n, int k)
{
    vector<int> answer;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    update_dist(1, 1, n, 1);

    for (int num = 2; num <= k; num++)
    {
        int maxD = 0;
        int maxI = 0;
        int maxJ = 0;

        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                int D = dist[i][j];

                if (D > maxD)
                {
                    maxD = D;
                    maxI = i;
                    maxJ = j;
                }
            }
        }

        update_dist(maxI, maxJ, n, num);
    }

    cout << info[k][0] << " " << info[k][1] << "\n";

    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution(5, 12); // 4, 4
    solution(5, 16); // 1, 2
    solution(6, 13); // 4, 5

    return 0;
}