#include <iostream>
#include <string>

using namespace std;

int N, M;
int coin[10];

string dp[51];

string cmp(string a, string b)
{
	if (a.length() != b.length())
	{
		if (a.length() > b.length())
		{
			if (a.length() > 1 && a[0] == '0')
			{
				return cmp(a.substr(1, a.length() - 1), b);
			}
			else return a;
		}
		else
		{
			if (b.length() > 1 && b[0] == '0')
			{
				return cmp(a, b.substr(1, b.length() - 1));
			}
			else return b;
		}
	}
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] > b[i]) return a;
			else if (a[i] < b[i]) return b;
		}
	}
}

void DP()
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i > coin[j])
			{
				string temp = cmp(to_string(j) + dp[i - coin[j]], dp[i - coin[j]] + to_string(j));
				dp[i] = cmp(dp[i], temp);
			}
			else if (i == coin[j])
			{
				dp[i] = cmp(dp[i], to_string(j));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}

	cin >> M;

	DP();

	cout << dp[M] << "\n";

	return 0;
}