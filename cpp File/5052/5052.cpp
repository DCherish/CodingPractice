#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
string s;

vector<string> answer;

void solve(vector<string> phone)
{
	bool state = true;

	sort(phone.begin(), phone.end());

	string prev_str = phone[0];

	for (int i = 1; i < phone.size(); i++)
	{
		string cur_str = phone[i];

		if (prev_str.length() > cur_str.length())
		{
			prev_str = cur_str;
			continue;
		}

		if (cur_str.substr(0, prev_str.length()) == prev_str)
		{
			state = false;
			break;
		}
		else
		{
			prev_str = cur_str;
		}
	}

	if (state == true)
	{
		answer.push_back("YES");
	}
	else
	{
		answer.push_back("NO");
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		vector<string> phone;

		cin >> n;

		cin.ignore(256, '\n');

		for (int j = 0; j < n; j++)
		{
			getline(cin, s);

			phone.push_back(s);
		}

		solve(phone);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}