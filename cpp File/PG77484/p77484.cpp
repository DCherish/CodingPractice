#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt, zero_cnt;

int rank_lotto[7] = { 6, 6, 5, 4, 3, 2, 1 };

bool cmp(int a, int b)
{
	return a > b;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;

	sort(lottos.begin(), lottos.end(), cmp);
	sort(win_nums.begin(), win_nums.end(), cmp);

	cnt = 0;
	zero_cnt = 0;

	for (int i = 0; i < lottos.size(); i++)
	{
		int temp = lottos[i];

		if (temp == 0) zero_cnt++;
		else
		{
			int tempcnt = upper_bound(win_nums.begin(), win_nums.end(), temp, cmp) - lower_bound(win_nums.begin(), win_nums.end(), temp, cmp);

			cnt += tempcnt;
		}
	}

	answer.push_back(rank_lotto[cnt + zero_cnt]);
	answer.push_back(rank_lotto[cnt]);

	return answer;
}