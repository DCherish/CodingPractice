#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> alpha;

int idx;

void init()
{
	for (int i = 1; i <= 26; i++)
	{
		string str = "";

		str += (char)(65 + i - 1);

		alpha[str] = i;
	}

	idx = 27;
}

vector<int> solution(string msg)
{
	vector<int> answer;

	init();

	string str = "";
	str += msg[0];

	string prev;

	for (int i = 1; i < msg.length(); i++)
	{
		prev = str;
		str += msg[i];

		if (alpha.count(str) == 0)
		{
			answer.push_back(alpha[prev]);

			alpha[str] = idx;
			idx++;

			str = "";
			str += msg[i];
		}
	}

	answer.push_back(alpha[str]);

	return answer;
}