#include <iostream>
#define Min(a, b) (a < b ? a : b)

using namespace std;

int N;
int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i <= N; i++)
	{
		dp[i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j * j <= i; j++)
		{
			dp[i] = Min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N] << "\n";

	return 0;
}