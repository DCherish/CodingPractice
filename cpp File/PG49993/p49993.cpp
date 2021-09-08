#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		string str = "";
		bool state = true;

		for (int j = 0; j < skill_trees[i].length(); j++)
		{
			for (int k = 0; k < skill.length(); k++)
			{
				if (skill[k] == skill_trees[i][j])
				{
					str += skill[k];
					break;
				}
			}
		}

		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] != skill[j])
			{
				state = false;
				break;
			}
		}

		if (state == true) answer++;
	}

	return answer;
}