#include <iostream>
#include <algorithm>
#define INT_MAX 9999999
#define Min(a, b) (a < b ? a : b)

using namespace std;

int n, k;
int cn[100];
int dp[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> cn[i];
	}

	fill(dp, dp + 10001, INT_MAX);

	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = cn[i]; j <= k; j++)
		{
			dp[j] = Min(dp[j], dp[j - cn[i]] + 1);
		}
	}

	if (dp[k] == 9999999)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << dp[k] << "\n";
	}

	return 0;
}