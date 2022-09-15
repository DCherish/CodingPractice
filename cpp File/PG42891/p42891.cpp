#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct info
{
    int time;
    int idx;
};

vector<info> vec;

bool cmp(info a, info b)
{
    return a.time < b.time;
}

bool cmp2(info a, info b)
{
    return a.idx < b.idx;
}

int solution(vector<int> food_times, ll k)
{
    int answer = -1;
    
    int N = food_times.size();
    
    for (int i = 0; i < N; i++)
    {
        vec.push_back({ food_times[i], i + 1 });
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    int prev = 0;
    int temp = N;
    
    for (int i = 0; i < N; i++, temp--)
    {
        ll diff = (ll)(vec[i].time - prev) * (ll)temp;
        
        if (diff == 0) continue;
        
        if (k - diff >= 0)
        {
            k -= diff;
            prev = vec[i].time;
        }
        else
        {
            k %= temp;
            sort(vec.begin() + i, vec.end(), cmp2);
            
            answer = vec[i + k].idx;
            break;
        }
    }
    
    return answer;
}