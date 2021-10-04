#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int st[] = { 1, 2, 3, 4, 5 };
int nd[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int rd[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

int cnt[3] = { 0, 0, 0 };
int maxcnt = 0;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;

	for (int i = 0; i < answers.size(); i++)
	{
		if (st[i % 5] == answers[i]) cnt[0]++;

		if (nd[i % 8] == answers[i]) cnt[1]++;

		if (rd[i % 10] == answers[i]) cnt[2]++;

		for (int j = 0; j < 3; j++)
		{
			maxcnt = max(maxcnt, cnt[j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (maxcnt == cnt[i]) answer.push_back(i + 1);
	}

	return answer;
}