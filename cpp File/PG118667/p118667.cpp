#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;

deque<int> DQ1;
deque<int> DQ2;

ll max1 = 0;
ll max2 = 0;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -1;
    
    ll sum1 = 0;
    ll sum2 = 0;
    
    int cnt = 0;
    
    for (int i = 0; i < queue1.size(); i++)
    {
        DQ1.push_back(queue1[i]);
        sum1 += (ll)queue1[i];
        max1 = max(max1, (ll)queue1[i]);
    }
    
    for (int i = 0; i < queue2.size(); i++)
    {
        DQ2.push_back(queue2[i]);
        sum2 += (ll)queue2[i];
        max2 = max(max2, (ll)queue2[i]);
    }
    
    ll half = (sum1 + sum2) / 2;
    
    if ((sum1 + sum2) % 2 == 1) return -1;
    if (max1 > half || max2 > half) return -1;
    
    while (true)
    {
        if (cnt > 3 * queue1.size()) return -1;
        
        if (sum1 == sum2)
        {
            answer = cnt;
            break;
        }
        else if (sum1 > sum2)
        {
            int num = DQ1.front();
            DQ1.pop_front();
            
            sum1 -= (ll)num;
            sum2 += (ll)num;
            
            DQ2.push_back(num);
        }
        else
        {
            int num = DQ2.front();
            DQ2.pop_front();
                
            sum1 += (ll)num;
            sum2 -= (ll)num;
            
            DQ1.push_back(num);
        }
            
        cnt++;
    }
    
    return answer;
}