#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> ST;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;

	int idx = 0;
	int turn = 0;

	string prev = "";

	for (int i = 0; i < words.size(); i++)
	{
		if (prev == "")
		{
			ST.insert(words[i]);
			prev = words[i];
		}
		else
		{
			if (prev[prev.length() - 1] != words[i][0])
			{
				idx = (i % n) + 1;
				turn = (i / n) + 1;
				break;
			}

			if (ST.count(words[i]) == 0)
			{
				ST.insert(words[i]);
				prev = words[i];
			}
			else
			{
				idx = (i % n) + 1;
				turn = (i / n) + 1;
				break;
			}
		}
	}

	answer.push_back(idx);
	answer.push_back(turn);

	return answer;
}