#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		return s1 < s2;
	}
	else return s1.length() < s2.length();
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	vector<string> strvec = words;
	vector<string> r_strvec;

	int cnt = 0;

	for (int i = 0; i < words.size(); i++)
	{
		string str = "";

		for (int j = words[i].length() - 1; j >= 0; j--)
		{
			str += words[i][j];
		}

		r_strvec.push_back(str);
	}

	sort(strvec.begin(), strvec.end(), cmp);
	sort(r_strvec.begin(), r_strvec.end(), cmp);

	for (int i = 0; i < queries.size(); i++)
	{
		int hi, lo;

		if (queries[i][0] == '?') // ?로 시작할 경우
		{
			string temp = "";
			string temp2 = "";

			for (int j = queries[i].length() - 1; j >= 0; j--)
			{
				if (queries[i][j] != '?')
				{
					temp += queries[i][j];
				}

				else break;
			}

			temp2 = temp;

			while (temp2.length() != queries[i].length())
			{
				temp2 += "z";
			}

			hi = upper_bound(r_strvec.begin(), r_strvec.end(), temp2, cmp) - r_strvec.begin();

			temp2 = temp;

			while (temp2.length() != queries[i].length())
			{
				temp2 += "a";
			}

			lo = lower_bound(r_strvec.begin(), r_strvec.end(), temp2, cmp) - r_strvec.begin();
		}
		else // ?로 시작하지 않을 경우
		{
			string temp = "";
			string temp2 = "";

			for (int j = 0; j < queries[i].length(); j++)
			{
				if (queries[i][j] != '?')
				{
					temp += queries[i][j];
				}

				else break;
			}

			temp2 = temp;

			while (temp2.length() != queries[i].length())
			{
				temp2 += "z";
			}

			hi = upper_bound(strvec.begin(), strvec.end(), temp2, cmp) - strvec.begin();

			temp2 = temp;

			while (temp2.length() != queries[i].length())
			{
				temp2 += "a";
			}

			lo = lower_bound(strvec.begin(), strvec.end(), temp2, cmp) - strvec.begin();
		}

		answer.push_back(hi - lo);
	}

	return answer;
}