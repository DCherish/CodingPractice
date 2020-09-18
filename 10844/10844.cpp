#include <iostream>
#define MOD 1000000000

using namespace std;

int N;

int dp[101][11] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i-1][1];

		for (int j = 1; j <= 9; j++)
		{
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
		}
	}

	int sum = 0;

	for (int i = 0; i <= 9; i++)
	{
		sum = sum + dp[N][i];
		sum = sum % MOD;
	}

	cout << sum << "\n";

	return 0;
}