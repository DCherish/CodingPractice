#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int T, K, num;
int arr[501];
int sum[501];
int dp[501][501];

vector<int> answer;

void solve()
{
	sum[1] = arr[1];

	for (int i = 2; i <= K; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int gap = 1; gap < K; gap++)
	{
		for (int start = 1; start + gap <= K; start++)
		{
			int end = start + gap;

			dp[start][end] = INT_MAX; // limits.h

			for (int mid = start; mid < end; mid++)
			{
				dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
			}
		}
	}

	answer.push_back(dp[1][K]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> K;

		for (int j = 1; j <= K; j++)
		{
			cin >> num;

			arr[j] = num;
		}

		solve();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}