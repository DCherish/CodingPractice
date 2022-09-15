#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll, ll> umap;

ll find(ll key)
{
    if (umap.count(key) == 0) return key;
    else return umap[key] = find(umap[key]);
}

vector<ll> solution(ll k, vector<ll> room_number)
{
    vector<ll> answer;
    
    for (int i = 0; i < room_number.size(); i++)
    {
        ll num = room_number[i];
        
        if (umap.count(num) == 0)
        {
            answer.push_back(num);
            
            umap[num] = find(num + 1);
        }
        else
        {
            ll next_num = find(num);
            
            answer.push_back(next_num);
            
            umap[next_num] = find(next_num + 1);
        }
    }
    
    return answer;
}