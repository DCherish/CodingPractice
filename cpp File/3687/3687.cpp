#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define INF LLONG_MAX

using namespace std;

int T, n;
long long num[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
long long dp[101] = { 0, 0, 1, 7, 4, 2, 6, 8, 10, };

vector<long long> min_vec;
vector<string> max_vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 9; i <= 100; i++)
	{
		dp[i] = INF;

		for (int j = 2; j <= 7; j++)
		{
			dp[i] = min(dp[i - j] * 10 + num[j], dp[i]);
		}
	}

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		min_vec.push_back(dp[n]);

		string str = "";

		if (n % 2 == 0)
		{
			int temp = n / 2;

			while (temp > 0)
			{
				str += '1';
				temp--;
			}
		}
		else
		{
			str += '7';

			int temp = n / 2 - 1;

			while (temp > 0)
			{
				str += '1';
				temp--;
			}
		}

		max_vec.push_back(str);
	}

	for (int i = 0; i < min_vec.size(); i++)
	{
		cout << min_vec[i] << " " << max_vec[i] << "\n";
	}

	return 0;
}