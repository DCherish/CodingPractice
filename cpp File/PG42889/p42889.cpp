#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int num;
	double rate;
};

int ing_cnt[510];
int all_cnt[510];

vector<info> vec;

bool cmp(info a, info b)
{
	if (a.rate == b.rate)
	{
		return a.num < b.num;
	}
	else return a.rate > b.rate;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	info temp;

	for (int i = 0; i < stages.size(); i++)
	{
		for (int j = 1; j <= stages[i]; j++)
		{
			all_cnt[j]++;
		}

		ing_cnt[stages[i]]++;
	}

	for (int i = 1; i <= N; i++)
	{
		temp.num = i;

		if (all_cnt[i] == 0) temp.rate = 0;
		else temp.rate = (double)ing_cnt[i] / (double)all_cnt[i];

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		answer.push_back(vec[i].num);
	}

	return answer;
}