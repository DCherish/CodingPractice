#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int maxlen = s.length();

	int len = s.length() / 2;

	for (int i = 1; i <= len; i++)
	{
		string prev = s.substr(0, i);
		answer = i;
		int cnt = 1;

		for (int j = i; j < s.length(); j = j + i)
		{
			string str = s.substr(j, i);

			if (prev.compare(str) == 0)
			{
				cnt++;
			}
			else
			{
				if (cnt != 1)
				{
					answer += to_string(cnt).length();
				}

				answer += str.length();
				prev = str;
				cnt = 1;
			}
		}

		if (cnt != 1)
		{
			answer += to_string(cnt).length();
		}

		if (answer < maxlen) maxlen = answer;
	}

	answer = maxlen;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s1 = "aabbaccc";
	string s2 = "ababcdcdababcdcd";
	string s3 = "abcabcdede";
	string s4 = "abcabcabcabcdededededede";
	string s5 = "xababcdcdababcdcd";
	string s6 = "aaaaaaaaaab";
	string s7 = "a";

	cout << solution(s1) << "\n";
	cout << solution(s2) << "\n";
	cout << solution(s3) << "\n";
	cout << solution(s4) << "\n";
	cout << solution(s5) << "\n";
	cout << solution(s6) << "\n";
	cout << solution(s7) << "\n";

	return 0;
}