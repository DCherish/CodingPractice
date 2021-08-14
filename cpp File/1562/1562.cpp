#include <iostream>
#define MODNUM 1000000000

using namespace std;

int N, ans;
int dp[101][10][1 << 10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int full_bit = (1 << 10) - 1;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= full_bit; k++)
			{
				if (j == 0)
				{
					dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MODNUM;
				}
				else if (j == 9)
				{
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MODNUM;
				}
				else
				{
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MODNUM;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MODNUM;
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		ans += dp[N][i][full_bit];
		ans %= MODNUM;
	}

	cout << ans << "\n";

	return 0;
}