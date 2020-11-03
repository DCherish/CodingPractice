#include <iostream>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int N, K;
int W[101];
int V[101];
int dp[101][100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if (j - W[i] >= 0)
			{
				dp[i][j] = Max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
			}			
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}