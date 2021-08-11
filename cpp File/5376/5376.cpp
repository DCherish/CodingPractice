#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int T;

vector<string> ans;

ll gcd(ll x, ll y)
{
	if (x < y)
	{
		ll temp = x;
		ll x = y;
		ll y = temp;
	}

	while (true)
	{
		if (x % y == 0) return y;
		else
		{
			ll temp = x % y;
			x = y;
			y = temp;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;

		int idx = -1;

		string full_str = "";

		for (int j = 2; j < str.length(); j++)
		{
			if (str[j] == '(') idx = j;

			if (str[j] == '(' || str[j] == ')') continue;
			else full_str += str[j];
		}

		if (idx != -1) // 괄호가 있을 때
		{
			if (idx == 2) // 괄호로 바로 시작할 때
			{
				ll full_num = stoll(full_str);
				int full_len = full_str.length();

				ll back_num = 9;

				for (int j = 1; j < full_len; j++)
				{
					back_num *= 10;
					back_num += 9;
				}

				ll gcd_num = gcd(full_num, back_num);

				string result = to_string(full_num / gcd_num) + "/" + to_string(back_num / gcd_num);

				ans.push_back(result);
			}
			else // 괄호로 바로 시작하지 않을 때
			{
				string front_str = str.substr(2, idx - 2);
				string back_str = str.substr(idx + 1, str.length() - idx - 2);

				int front_len = front_str.length();
				int back_len = back_str.length();

				ll front_num = stoll(full_str) - stoll(front_str);
				ll back_num = 9;

				for (int j = 1; j < back_len; j++)
				{
					back_num *= 10;
					back_num += 9;
				}

				for (int j = 0; j < front_len; j++)
				{
					back_num *= 10;
				}

				ll gcd_num = gcd(front_num, back_num);

				string result = to_string(front_num / gcd_num) + "/" + to_string(back_num / gcd_num);

				ans.push_back(result);
			}
		}
		else // 괄호가 없을 때
		{
			ll full_num = stoi(full_str);
			int full_len = full_str.length();

			ll back_num = 10;

			for (int j = 1; j < full_len; j++)
			{
				back_num *= 10;
			}

			ll gcd_num = gcd(full_num, back_num);

			string result = to_string(full_num / gcd_num) + "/" + to_string(back_num / gcd_num);

			ans.push_back(result);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}