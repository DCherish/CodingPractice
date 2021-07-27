#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];
int dp[501][501];

int maxcost;

void DP()
{
	dp[1][1] = arr[1][1];
	maxcost = dp[1][1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);

			if (dp[i][j] > maxcost)
			{
				maxcost = dp[i][j];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	DP();

	cout << maxcost << "\n";

	return 0;
}