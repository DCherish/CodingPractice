#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

struct info
{
	int num;
	int idx;
	int cnt;
};

int N, T, X;

int idx[101];
int cnt[101];

vector<int> vec;

bool cmp(info a, info b)
{
	if (a.cnt == b.cnt)
	{
		return a.idx < b.idx;
	}
	else return a.cnt < b.cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> X;

		if (vec.size() < N)
		{
			if (cnt[X] == 0)
			{
				vec.push_back(X);
				cnt[X]++;
			}
			else
			{
				cnt[X]++;
			}
		}
		else if (vec.size() == N)
		{
			memset(idx, 0, sizeof(idx));

			for (int i = 0; i < vec.size(); i++)
			{
				idx[vec[i]] = i + 1;
			}

			if (cnt[X] == 0)
			{
				deque<info> DQ;

				for (int i = 0; i < vec.size(); i++)
				{
					DQ.push_back({ vec[i], idx[vec[i]], cnt[vec[i]] });
				}

				sort(DQ.begin(), DQ.end(), cmp);

				int temp = DQ.front().num;
				DQ.pop_front();

				cnt[temp] = 0;

				vector<int> t_vec;

				for (int i = 0; i < vec.size(); i++)
				{
					if (cnt[vec[i]] == 0) continue;
					else t_vec.push_back(vec[i]);
				}

				vec.clear();
				vec = t_vec;

				vec.push_back(X);
				cnt[X]++;
			}
			else
			{
				cnt[X]++;
			}
		}
	}

	sort(vec.begin(), vec.end(), less<int>());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	cout << "\n";

	return 0;
}