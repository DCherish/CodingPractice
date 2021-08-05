#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;

string s1 = "0";
string s2 = "1";
string ans;

string sum(string a, string b)
{
	string result(max(a.size(), b.size()), '0');
	int carry = 0;

	for (int i = 0; i < result.size(); i++)
	{
		int temp = carry;
		carry = 0;

		if (i < a.size())
		{
			temp += a[a.size() - i - 1] - '0';
		}

		if (i < b.size())
		{
			temp += b[b.size() - i - 1] - '0';
		}

		if (temp >= 10)
		{
			carry = 1;
			temp -= 10;
		}

		result[result.size() - i - 1] = temp + '0';
	}

	if (carry == 1) result.insert(result.begin(), '1');

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	if (n == 0 || n == 1)
	{
		cout << n << "\n";
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			ans = sum(s1, s2);

			s1 = s2;
			s2 = ans;
		}

		cout << ans << "\n";
	}

	return 0;
}