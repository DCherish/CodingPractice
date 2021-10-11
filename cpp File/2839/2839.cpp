#include <iostream>
#include <algorithm>
#define Min(a, b) (a < b ? a : b)

using namespace std;

int N;

int dp[5001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(dp, dp + 5001, -1);

	cin >> N;

	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++)
	{
		if (dp[i - 5] == -1)
		{
			if (dp[i - 3] == -1)
			{
				continue;
			}

			dp[i] = dp[i - 3] + 1;
		}
		else if (dp[i - 3] == -1)
		{
			dp[i] = dp[i - 5] + 1;
		}
		else
		{
			dp[i] = Min(dp[i - 3] + 1, dp[i - 5] + 1);
		}
	}

	cout << dp[N] << "\n";

	return 0;
}