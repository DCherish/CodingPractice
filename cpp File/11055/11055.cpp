#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

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
				temp = dp[j];
			}

			if (temp > dtemp)
			{
				dtemp = temp;
			}
		}

		dp[i] = dtemp + arr[i];

		if (dp[i] > maxcost)
		{
			maxcost = dp[i];
		}
	}

	cout << maxcost << "\n";

	return 0;
}