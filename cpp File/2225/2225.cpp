#include <iostream>

using namespace std;

long long dp[201][201];
int N, K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= K; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] = dp[i][j] % 1000000000;
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}