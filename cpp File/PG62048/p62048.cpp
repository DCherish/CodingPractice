#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll r)
{
    if (x < r) swap(x, r);
    
    while (x % r != 0)
    {
        ll temp = x % r;
        x = r;
        r = temp;
    }
    
    return r;
}

ll solution(int w, int h) 
{
    ll answer = 1;
    
    ll width = (ll)w;
    ll height = (ll)h;
    
    answer = width * height - (width + height - gcd(width, height));
    
    return answer;
}