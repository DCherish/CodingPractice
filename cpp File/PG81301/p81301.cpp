#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
	int answer = 0;

	string str = "";

	for (int i = 0; i < s.length();)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			str += s[i];
			i += 1;
		}
		else if (s[i] == 'z')
		{
			str += '0';
			i += 4;
		}
		else if (s[i] == 'o')
		{
			str += '1';
			i += 3;
		}
		else if (s[i] == 'e')
		{
			str += '8';
			i += 5;
		}
		else if (s[i] == 'n')
		{
			str += '9';
			i += 4;
		}
		else if (s[i] == 't')
		{
			if (s[i + 2] == 'o')
			{
				str += '2';
				i += 3;
			}
			else
			{
				str += '3';
				i += 5;
			}
		}
		else if (s[i] == 'f')
		{
			if (s[i + 3] == 'r')
			{
				str += '4';
				i += 4;
			}
			else
			{
				str += '5';
				i += 4;
			}
		}
		else if (s[i] == 's')
		{
			if (s[i + 2] == 'x')
			{
				str += '6';
				i += 3;
			}
			else
			{
				str += '7';
				i += 5;
			}
		}
	}

	for (int i = 0; i < str.length(); i++)
	{
		answer *= 10;
		answer += (int)(str[i] - '0');
	}

	return answer;
}