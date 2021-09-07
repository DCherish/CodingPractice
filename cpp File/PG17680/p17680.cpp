#include <string>
#include <vector>
#include <deque>
#include <set>

using namespace std;

deque<string> DQ;
set<string> ST;

void cnvert(int idx, vector<string>& cities)
{
	for (int i = 0; i < cities[idx].length(); i++)
	{
		if (cities[idx][i] >= 'a' && cities[idx][i] <= 'z')
		{
			cities[idx][i] -= 'a';
			cities[idx][i] += 'A';
		}
	}
}

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;

	if (cacheSize == 0)
	{
		answer = (5 * cities.size());
	}
	else
	{
		for (int i = 0; i < cities.size(); i++)
		{
			cnvert(i, cities);

			if (ST.count(cities[i]) == 0)
			{
				if (DQ.size() < cacheSize)
				{
					DQ.push_back(cities[i]);
					ST.insert(cities[i]);
				}
				else
				{
					string temp = DQ.front();
					DQ.pop_front();

					ST.erase(temp);

					DQ.push_back(cities[i]);
					ST.insert(cities[i]);
				}

				answer += 5;
			}
			else
			{
				deque<string> tempDQ;

				while (true)
				{
					if (DQ.front() == cities[i])
					{
						DQ.pop_front();
						DQ.push_back(cities[i]);
						break;
					}
					else
					{
						tempDQ.push_back(DQ.front());
						DQ.pop_front();
					}
				}

				while (!tempDQ.empty())
				{
					DQ.push_front(tempDQ.back());
					tempDQ.pop_back();
				}

				answer += 1;
			}
		}
	}

	return answer;
}