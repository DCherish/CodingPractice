#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string s1, s2;

int DP[1001][1001];

stack<char> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s1;
	cin >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	if (DP[len1][len2] == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << DP[len1][len2] << "\n";

		while (DP[len1][len2] != 0)
		{
			if (DP[len1][len2] == DP[len1][len2 - 1]) len2--;
			else if (DP[len1][len2] == DP[len1 - 1][len2]) len1--;
			else if (DP[len1][len2] - 1 == DP[len1 - 1][len2 - 1])
			{
				ans.push(s1[len1 - 1]);
				len1--;
				len2--;

			}
		}

		while (!ans.empty())
		{
			cout << ans.top();
			ans.pop();
		}

		cout << "\n";
	}

	return 0;
}