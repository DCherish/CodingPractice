#include <iostream>
#define MOD 100000

using namespace std;

int w, h;
int DP[101][101][4]; // 0 uu, 1 ru, 2 rr, 3 ur

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h;

	for (int i = 1; i <= w; i++)
	{
		DP[i][1][2] = 1;
	}

	for (int i = 1; i <= h; i++)
	{
		DP[1][i][0] = 1;
	}

	for (int i = 2; i <= w; i++)
	{
		for (int j = 2; j <= h; j++)
		{
			// 아래에서
			DP[i][j][0] = (DP[i][j - 1][0] + DP[i][j - 1][1]) % MOD;
			DP[i][j][1] = DP[i][j - 1][2];

			// 왼쪽에서
			DP[i][j][2] = (DP[i - 1][j][2] + DP[i - 1][j][3]) % MOD;
			DP[i][j][3] = DP[i - 1][j][0];
		}
	}

	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		ans += DP[w][h][i];
	}

	cout << ans % MOD << "\n";

	return 0;
}