#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[31];

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 1;
    }
    
    for (int i = 0; i < reserve.size(); i++)
    {
        cnt[reserve[i]] += 1;
    }
    
    for (int i = 0; i < lost.size(); i++)
    {
        cnt[lost[i]] -= 1;
    }
    
    if (cnt[1] == 0 && cnt[2] == 2)
    {
        cnt[1] += 1;
        cnt[2] -= 1;
    }
    
    if (cnt[n] == 0 && cnt[n - 1] == 2)
    {
        cnt[n] += 1;
        cnt[n - 1] -= 1;
    }
    
    for (int i = 2; i <= n - 1; i++)
    {
        if (cnt[i] == 0)
        {
            if (cnt[i - 1] == 2)
            {
                cnt[i] += 1;
                cnt[i - 1] -= 1;
            }
            else if (cnt[i + 1] == 2)
            {
                cnt[i] += 1;
                cnt[i + 1] -= 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] >= 1) answer++;
    }
    
    return answer;
}