#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N;
int arr[1001];
int dp[1001][1001];

vector<int> ans;

int solve(int left, int right, int turn)
{
	if (left > right) return 0;

	if (dp[left][right] != 0) return dp[left][right];

	if (turn % 2 != 0)
	{
		return dp[left][right] = max(arr[left] + solve(left + 1, right, turn + 1), arr[right] + solve(left, right - 1, turn + 1));
	}
	else
	{
		return dp[left][right] = min(solve(left + 1, right, turn + 1), solve(left, right - 1, turn + 1));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));

		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}

		solve(0, N - 1, 1);

		ans.push_back(dp[0][N - 1]);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}