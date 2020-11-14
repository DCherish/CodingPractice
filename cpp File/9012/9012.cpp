#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
vector<string> answer;

string s;
int T;

bool isValid(string str)
{
	stack<char> stk;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			stk.push('(');
		}
		else
		{
			if (stk.empty()) return false;

			stk.pop();
		}
	}

	if (stk.empty()) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++)
	{
		getline(cin, s);

		if (isValid(s) == true)
		{
			answer.push_back("YES");
		}
		else
		{
			answer.push_back("NO");

		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}