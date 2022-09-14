#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = INT_MAX;
    
    int sz = weak.size();
    
    for (int i = 0; i < sz - 1; i++)
    {
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end());
    
    do
    {
        for (int i = 0; i < sz; i++)
        {
            int start = weak[i];
            int end = weak[i + sz - 1];
            
            int temp = i + 1;
            
            for (int j = 0; j < dist.size(); j++)
            {
                start += dist[j];
                
                if (start >= end)
                {
                    answer = min(answer, j + 1);
                    break;
                }
                
                for (int k = temp; k < i + sz; k++)
                {
                    if (weak[k] > start)
                    {
                        start = weak[k];
                        temp = k + 1;
                        break;
                    }
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    
    if (answer == INT_MAX) answer = -1;
    
    return answer;
}