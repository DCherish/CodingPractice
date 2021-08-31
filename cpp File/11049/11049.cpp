#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
int arr[501][2];
int dp[501][501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int gap = 1; gap < N; gap++)
	{
		for (int i = 1; i + gap <= N; i++)
		{
			dp[i][i + gap] = INT_MAX;

			for (int j = i; j <= i + gap; j++)
			{
				dp[i][i + gap] = min(dp[i][i + gap], dp[i][j] + dp[j + 1][i + gap] + arr[i][0] * arr[j][1] * arr[i + gap][1]);
			}
		}
	}

	cout << dp[1][N] << "\n";

	return 0;
}