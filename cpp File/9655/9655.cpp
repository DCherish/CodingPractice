#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dp[1] = 1; // 돌 1개 남았을 때 반드시 S 승리
	dp[2] = 0; // 돌 2개 남았을 때 반드시 C 승리
	dp[3] = 1; // 돌 3개 남았을 때 반드시 S 승리
	dp[4] = 0; // 돌 3개 남았을 때 반드시 S 승리

	for (int i = 5; i <= N; i++)
	{
		if (min(dp[i - 1], dp[i - 3]) == 1)
		{
			dp[i] = 0;
		}
		else dp[i] = 1;
	}

	if (dp[N] == 1) cout << "SK" << "\n";
	else cout << "CY" << "\n";

	return 0;
}