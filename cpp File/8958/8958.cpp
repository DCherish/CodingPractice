#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
vector<int> answer;
int cnt, temp;

void function(string s)
{
	cnt = 1;
	temp = 0;

	for (int i = 1; i <= s.length(); i++)
	{
		if (s[i - 1] == 'O')
		{
			temp = temp + cnt;
			cnt++;
		}
		else
		{
			cnt = 1;
		}
	}

	answer.push_back(temp);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	cin.ignore(); // getline 문제가 없도록

	for (int i = 0; i < T; i++)
	{
		string s;

		getline(cin, s);

		function(s);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}