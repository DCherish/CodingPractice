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

	dp[1] = 1; // �� 1�� ������ �� �ݵ�� S �¸�
	dp[2] = 0; // �� 2�� ������ �� �ݵ�� C �¸�
	dp[3] = 1; // �� 3�� ������ �� �ݵ�� S �¸�
	dp[4] = 0; // �� 3�� ������ �� �ݵ�� S �¸�

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