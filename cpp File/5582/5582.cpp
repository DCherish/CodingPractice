#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s1, s2;

int DP[4001][4001];

int ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s2.length(); i++)
	{
		for (int j = 1; j <= s1.length(); j++)
		{
			if (s2[i - 1] == s1[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;

				ans = max(ans, DP[i][j]);
			}
			else
			{
				DP[i][j] = 0;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}