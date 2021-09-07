#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

deque<ll> DQ;
deque<ll> DQ_cpy;

int oper[3];
bool visited[3];
vector<int> opvec;

ll answer = 0;

ll cal(int cnt)
{
	DQ_cpy.clear();
	DQ_cpy = DQ;

	for (int i = 0; i < cnt; i++)
	{
		int j = 1;

		while (j < DQ_cpy.size())
		{
			if (DQ_cpy[j] == opvec[i])
			{
				if (opvec[i] == 0)
				{
					DQ_cpy[j - 1] += DQ_cpy[j + 1];
					DQ_cpy.erase(DQ_cpy.begin() + j, DQ_cpy.begin() + j + 2);
				}
				else if (opvec[i] == 1)
				{
					DQ_cpy[j - 1] -= DQ_cpy[j + 1];
					DQ_cpy.erase(DQ_cpy.begin() + j, DQ_cpy.begin() + j + 2);
				}
				else if (opvec[i] == 2)
				{
					DQ_cpy[j - 1] *= DQ_cpy[j + 1];
					DQ_cpy.erase(DQ_cpy.begin() + j, DQ_cpy.begin() + j + 2);
				}
			}
			else j += 2;
		}
	}

	return abs(DQ_cpy.front());
}

void DFS(int cnt, int depth)
{
	if (cnt == depth)
	{
		answer = max(answer, cal(cnt));
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (oper[i] == 0) continue;
		if (visited[i] == true) continue;

		visited[i] = true;
		opvec.push_back(i);

		DFS(cnt, depth + 1);

		opvec.pop_back();
		visited[i] = false;

	}
}

ll solution(string expression)
{
	memset(oper, 0, sizeof(oper));
	memset(visited, false, sizeof(visited));

	string str = "";

	for (int i = 0; i < expression.length();)
	{
		if (expression[i] == '+')
		{
			oper[0]++;
			DQ.push_back(0);
			i++;
		}
		else if (expression[i] == '-')
		{
			oper[1]++;
			DQ.push_back(1);
			i++;
		}
		else if (expression[i] == '*')
		{
			oper[2]++;
			DQ.push_back(2);
			i++;
		}
		else
		{
			string str = "";
			ll sum = 0;

			while (expression[i] >= '0' && expression[i] <= '9')
			{
				str += expression[i];
				i++;
			}

			for (int j = 0; j < str.length(); j++)
			{
				sum *= 10;
				sum += (ll)str[j] - (ll)'0';
			}

			DQ.push_back(sum);
		}
	}

	int cnt = 0;

	for (int i = 0; i < 3; i++)
	{
		if (oper[i] != 0) cnt++;
	}

	DFS(cnt, 0);

	return answer;
}