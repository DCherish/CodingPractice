#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

map<string, int> MAP;

int maxscore = -1;

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
	string answer;

	for (int i = 0; i < languages.size(); i++)
	{
		MAP[languages[i]] = preference[i];
	}

	for (int i = 0; i < table.size(); i++)
	{
		stringstream ss(table[i]);
		string token;

		vector<string> temp;

		while (getline(ss, token, ' '))
		{
			temp.push_back(token);
		}

		int sum = 0;

		for (int j = 1; j < temp.size(); j++)
		{
			if (MAP.count(temp[j]) != 0)
			{
				sum += MAP[temp[j]] * (6 - j);
			}
		}

		if (sum > maxscore)
		{
			answer = temp[0];

			maxscore = sum;
		}
		else if (sum == maxscore && maxscore != -1)
		{
			answer = min(temp[0], answer);
		}
	}

	return answer;
}