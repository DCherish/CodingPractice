#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

set<int> ST;

bool cmp(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}

vector<int> solution(string s)
{
	vector<int> answer;

	vector<vector<int>> vec;

	stringstream ss(s);
	string token;

	while (getline(ss, token, '}'))
	{
		if (token == "") break;

		string str = "";

		vector<int> temp;

		for (int i = 2; i < token.length(); i++)
		{
			if (token[i] >= '0' && token[i] <= '9')
			{
				str += token[i];
			}
			else if (token[i] == ',')
			{
				temp.push_back(stoi(str));

				str = "";
			}
		}

		temp.push_back(stoi(str));

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (ST.count(vec[i][j]) == 0)
			{
				ST.insert(vec[i][j]);

				answer.push_back(vec[i][j]);

				break;
			}
		}
	}

	return answer;
}