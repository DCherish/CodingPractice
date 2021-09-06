#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	double rate;
	int cnt;
	int weight;
	int idx;
};

vector<info> vec;

bool cmp(info a, info b)
{
	if (a.rate == b.rate)
	{
		if (a.cnt == b.cnt)
		{
			if (a.weight == b.weight)
			{
				return a.idx < b.idx;
			}
			else return a.weight > b.weight;
		}
		else return a.cnt > b.cnt;
	}
	else return a.rate > b.rate;
}

vector<int> solution(vector<int> weights, vector<string> head2head)
{
	vector<int> answer;

	for (int i = 0; i < head2head.size(); i++)
	{
		double wincnt = 0;
		double losecnt = 0;

		int heavycnt = 0;

		for (int j = 0; j < head2head[i].length(); j++)
		{
			if (head2head[i][j] == 'L') losecnt++;
			else if (head2head[i][j] == 'W')
			{
				wincnt++;

				if (weights[i] < weights[j]) heavycnt++;
			}
		}

		if (wincnt == 0 && losecnt == 0)
		{
			vec.push_back({ 0, heavycnt, weights[i], i + 1 });
		}
		else
		{
			double rate = (wincnt) / (wincnt + losecnt);

			vec.push_back({ rate, heavycnt, weights[i], i + 1 });
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		answer.push_back(vec[i].idx);
	}

	return answer;
}