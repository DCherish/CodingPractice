#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;

ll sum1 = 0;
ll sum2 = 0;

ll max1 = 0;
ll max2 = 0;

deque<ll> DQ1;
deque<ll> DQ2;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -1;
    
    int sz = queue1.size();
    
    for (int i = 0; i < sz; i++)
    {
        ll q1 = (ll)queue1[i];
        ll q2 = (ll)queue2[i];
        
        sum1 += q1;
        sum2 += q2;
        
        max1 = max(max1, q1);
        max2 = max(max2, q2);
        
        DQ1.push_back(q1);
        DQ2.push_back(q2);
    }
    
    ll h_sum = (sum1 + sum2) / 2;
    ll r_sum = (sum1 + sum2) % 2;
    
    if (r_sum != 0) return -1;
    if (max1 > h_sum || max2 > h_sum) return -1;
    
    int cnt = 0;
    
    while (cnt < sz * 3)
    {
        if (sum1 == sum2)
        {
            answer = cnt;
            break;
        }
        else if (sum1 > sum2)
        {
            ll num = DQ1.front();
            DQ1.pop_front();
            
            sum1 -= num;
            
            DQ2.push_back(num);
            
            sum2 += num;
        }
        else
        {
            ll num = DQ2.front();
            DQ2.pop_front();
            
            sum2 -= num;
            
            DQ1.push_back(num);
            
            sum1 += num;
        }
        
        cnt++;
    }
    
    return answer;
}