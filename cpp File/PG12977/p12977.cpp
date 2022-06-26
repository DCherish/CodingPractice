#include <vector>
#include <cstring>
#include <cmath>
#define N 3000

using namespace std;

bool prime[N + 1];
int result = 0;

vector<int> vec;

void get_prime()
{
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (prime[i] == false) continue;
        
        for (int j = i * i; j <= N; j += i)
        {
            prime[j] = false;
        }
    }
}

void DFS(int depth, int idx, int sum)
{
    if (depth == 3)
    {
        if (prime[sum] == true)
        {
            result++;
        }
        
        return;
    }
    
    for (int i = idx; i < vec.size(); i++)
    {
        DFS(depth + 1, i + 1, sum + vec[i]);
    }
}

int solution(vector<int> nums)
{
    int answer = -1;

    vec = nums;
    
    memset(prime, true, sizeof(prime));
    
    get_prime();
    
    DFS(0, 0, 0);
    
    answer = result;

    return answer;
}