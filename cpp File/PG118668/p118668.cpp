#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int dp[200][200];

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int answer = 0;
    
    int max_a = 0;
    int max_c = 0;
    
    for (int i = 0; i < problems.size(); i++)
    {
        max_a = max(max_a, problems[i][0]);
        max_c = max(max_c, problems[i][1]);
    }
    
    if (alp >= max_a && cop >= max_c) return 0;
    
    if (alp >= max_a) alp = max_a;
    if (cop >= max_c) cop = max_c;
    
    for (int i = alp; i <= max_a; i++)
    {
        for (int j = cop; j <= max_c; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    
    dp[alp][cop] = 0;
    
    for (int i = alp; i <= max_a; i++)
    {
        for (int j = cop; j <= max_c; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            
            for (auto p : problems)
            {
                if (i >= p[0] && j >= p[1])
                {
                    if (i + p[2] > max_a && j + p[3] > max_c)
                    {
                        dp[max_a][max_c] = min(dp[max_a][max_c], dp[i][j] + p[4]);
                    }
                    else if (i + p[2] > max_a)
                    {
                        dp[max_a][j + p[3]] = min(dp[max_a][j + p[3]], dp[i][j] + p[4]);
                    }
                    else if (j + p[3] > max_c)
                    {
                        dp[i + p[2]][max_c] = min(dp[i + p[2]][max_c], dp[i][j] + p[4]);
                    }
                    else
                    {
                        dp[i + p[2]][j + p[3]] = min(dp[i + p[2]][j + p[3]], dp[i][j] + p[4]);
                    }
                }
            }
        }
    }
    
    answer = dp[max_a][max_c];
    
    return answer;
}