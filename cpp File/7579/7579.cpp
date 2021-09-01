#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;

int N, M, total;
int ans = INT_MAX;

int m[101];
int c[101];
int dp[101][10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> m[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
		total += c[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= total; j++)
		{
			if (j - c[i] >= 0)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + m[i]);
			}

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);

			if (dp[i][j] >= M)
			{
				ans = min(ans, j);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}