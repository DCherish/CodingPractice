#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, dp[100000];

int solve(int idx, vector<int>& sticker)
{
	memset(dp, 0, sizeof(dp));

	if (idx == 0)
	{
		dp[1] = sticker[1];

		for (int i = 2; i < N; i++)
		{
			dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
		}

		return dp[N - 1];
	}
	else
	{
		dp[0] = sticker[0];
		dp[1] = max(sticker[0], sticker[1]);

		for (int i = 2; i < N - 1; i++)
		{
			dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
		}

		return dp[N - 2];
	}
}

int solution(vector<int> sticker)
{
	int answer = 0;

	N = sticker.size();

	if (N == 1)
	{
		answer = sticker[0];
	}
	else
	{
		answer = solve(sticker[0], sticker);
		answer = max(answer, solve(0, sticker));
	}

	return answer;
}