#include <iostream>
#include <string>
#include <deque>

using namespace std;

int temp = 0;
string s;

deque<string> DQ;
deque<string> answer;

int state = 0;
int sum = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+')
		{
			DQ.push_back(s.substr(temp, i - temp));
			DQ.push_back("+");
			temp = i + 1;
		}
		else if (s[i] == '-')
		{
			DQ.push_back(s.substr(temp, i - temp));
			DQ.push_back("-");
			temp = i + 1;
		}
	}

	DQ.push_back(s.substr(temp, s.length() - temp));

	if (DQ.front() == "")
	{
		DQ.pop_front();
	}

	while (!DQ.empty())
	{
		string tempstr = DQ.front();
		DQ.pop_front();

		if (tempstr == "+")
		{
			int a = stoi(answer.back());
			answer.pop_back();

			int b = stoi(DQ.front());
			DQ.pop_front();

			answer.push_back(to_string(a + b));
		}
		else
		{
			answer.push_back(tempstr);
		}
	}

	if (answer[0] == "-")
	{
		for (int i = 1; i < answer.size(); i = i + 2)
		{
			sum = sum - stoi(answer[i]);
		}
	}
	else
	{
		sum = stoi(answer[0]);

		for (int i = 2; i < answer.size(); i = i + 2)
		{
			sum = sum - stoi(answer[i]);
		}
	}

	cout << sum << "\n";

	return 0;
}