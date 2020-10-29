#include <iostream>

using namespace std;

int N, K;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;

		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] = dp[i][j] % 10007;
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}