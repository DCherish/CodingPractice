#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;
typedef long long ll;

bool isprime(ll num)
{
    if (num <= 1) return false;
    
    for (ll i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    
    return true;
}

string cnvert(int n, int k)
{
    if (n < k) return to_string(n);
    
    int front = n / k;
    int back = n % k;
    
    return cnvert(front, k) + cnvert(back, k);
}

int solution(int n, int k)
{
    int answer = 0;
    
    string str = cnvert(n, k);
    
    stringstream ss(str);
    string token;
    
    vector<string> vec;
    
    while (getline(ss, token, '0'))
    {
        vec.push_back(token);
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == "") continue;
        if (isprime(stoll(vec[i]))) answer++;
    }
    
    return answer;
}