#include <iostream>
#include <string>
#define Max(a, b) (a > b ? a : b)

using namespace std;

char apb1[1001];
char apb2[1001];

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;

	getline(cin, s1);
	for (int i = 1; i <= s1.size(); i++)
	{
		apb1[i] = s1[i - 1];
	}

	getline(cin, s2);
	for (int i = 1; i <= s2.size(); i++)
	{
		apb2[i] = s2[i - 1];
	}

	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (apb1[i] == apb2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << "\n";

	return 0;
}