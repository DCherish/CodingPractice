#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> vec;

void DFS(int cnt, int depth, int idx, int visited, vector<vector<string>> relation)
{
	if (cnt == depth)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			int temp = (visited & vec[i]);

			if (vec[i] - temp == 0) return;
		}

		set<string> ST;

		for (int i = 0; i < relation.size(); i++)
		{
			string str = "";

			for (int j = 0; j < relation[i].size(); j++)
			{
				if ((visited & (1 << j)) != 0)
				{
					str += relation[i][j];
				}
			}

			if (ST.count(str) != 0) return;

			ST.insert(str);
		}

		vec.push_back(visited);

		return;
	}

	for (int i = idx; i < relation[0].size(); i++)
	{
		visited += (1 << i);
		DFS(cnt, depth + 1, i + 1, visited, relation);
		visited -= (1 << i);
	}
}

int solution(vector<vector<string>> relation)
{
	int answer = 0;

	int col = relation[0].size();

	for (int i = 1; i <= col; i++)
	{
		DFS(i, 0, 0, 0, relation);
	}

	answer = vec.size();

	return answer;
}