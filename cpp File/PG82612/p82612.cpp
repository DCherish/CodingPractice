using namespace std;
typedef long long ll;

long long solution(int price, int money, int count)
{
    ll answer = 0;

    ll sum = 0;

    for (int i = 1; i <= count; i++)
    {
        sum += (ll)i * (ll)price;
    }

    if (sum - money > 0) answer = sum - (ll)money;

    return answer;
}