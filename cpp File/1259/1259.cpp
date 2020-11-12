#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> answer;

int num;
string s;
int len;
int cnt;

int main()
{
	for (;;)
	{
		cin >> num;

		if (num == 0) break;
		else
		{
			s = to_string(num);

			len = s.length() / 2;
			cnt = 0;

			for (int i = 0; i < len; i++)
			{
				if (s[i] == s[s.length() - 1 - i])
				{
					cnt++;
				}
				else break;
			}

			if (cnt == len)
			{
				answer.push_back("yes");
			}
			else answer.push_back("no");
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}