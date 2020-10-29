#include <iostream>

using namespace std;

int N;

int dp[31];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= N; i = i + 2)
	{
		dp[i] = 3 * dp[i - 2];

		for (int j = i - 4; j >= 0; j = j - 2)
		{
			dp[i] = dp[i] + 2 * dp[j];
		}
	}

	cout << dp[N] << "\n";

	return 0;
}