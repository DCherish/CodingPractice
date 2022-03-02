#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool state;
int maxcost = 0;

bool cmp(string a, string b)
{
	int a_len = a.length();
	int cnt;

	for (int i = 0; i < b.length(); i++)
	{
		cnt = 0;

		for (int j = 0; j < a_len; j++)
		{
			if (i + j < b.length() && a[j] == b[i + j])
			{
				cnt++;

				if (cnt == a_len)
				{
                    if (i + j + 1 == b.length()) return true;
					if (b[i + j + 1] != '#') return true;
					else break;
				}
			}
			else break;
		}
	}

	return false;
}

int cnvert(string s)
{
	int hour = 0;
	int minute = 0;

	hour += (int)(s[0] - '0');
	hour *= 10;

	hour += (int)(s[1] - '0');

	minute += (int)(s[3] - '0');
	minute *= 10;

	minute += (int)(s[4] - '0');

	minute += (60 * hour);

	return minute;
}

string solution(string m, vector<string> musicinfos)
{
	string answer = "(None)";

	for (int i = 0; i < musicinfos.size(); i++)
	{
		vector<string> vec;

		stringstream ss(musicinfos[i]);
		string token;

		while (getline(ss, token, ','))
		{
			vec.push_back(token);
		}

		string s1 = vec[0];
		string s2 = vec[1];
		string s3 = vec[2];
		string s4 = vec[3];

		int start = cnvert(s1);
		int end = cnvert(s2);

		string temp = "";

		int idx = 0;
		int sharp_cnt = 0;

		state = false;

		for (int j = 0; j < end - start + sharp_cnt; j++)
		{
			temp += s4[idx];
			idx++;

			if (idx == s4.length()) idx = 0;

			if (s4[idx] == '#') sharp_cnt++;
		}

		if (cmp(m, temp) == true)
		{
			if (end - start > maxcost)
			{
				maxcost = end - start;

				answer = s3;
			}
		}
	}

	return answer;
}