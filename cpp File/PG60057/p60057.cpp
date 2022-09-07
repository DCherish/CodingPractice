#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int minlen = s.length();

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

		minlen = min(minlen, answer);
	}

	answer = minlen;

	return answer;
}