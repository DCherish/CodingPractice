#include <iostream>

using namespace std;

int arr[1001];
int inc_dp[1001];
int dec_dp[1002];

int N;
int maxcost = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		int dtemp = 0;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = inc_dp[j];
			}

			if (temp > dtemp)
			{
				dtemp = temp;
			}
		}

		inc_dp[i] = dtemp + 1;
	}

	for (int i = N; i >= 1; i--)
	{
		int temp = 0;
		int dtemp = 0;

		for (int j = N + 1; j > i; j--)
		{
			if (arr[j] < arr[i])
			{
				temp = dec_dp[j];
			}

			if (temp > dtemp)
			{
				dtemp = temp;
			}
		}

		dec_dp[i] = dtemp + 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (inc_dp[i] + dec_dp[i] > maxcost)
		{
			maxcost = inc_dp[i] + dec_dp[i] - 1;
		}
	}

	cout << maxcost << "\n";

	return 0;
}