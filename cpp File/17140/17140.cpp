#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct info
{
	int num;
	int cnt;
};

int r, c, k, num;
int visited[101];
int MAP[101][101];

int result = 0;

bool cmp(info a, info b)
{
	if (a.cnt == b.cnt)
	{
		return a.num < b.num;
	}
	else return a.cnt < b.cnt;
}

void init()
{
	for (int i = 0; i <= 100; i++)
	{
		visited[i] = 0;
	}
}

void Find()
{
	int time = 0;
	int r_cnt = 3; // 행 개수
	int c_cnt = 3; // 열 개수

	while (true)
	{
		if (MAP[r][c] == k)
		{
			result = time;
			break;
		}

		if (time > 100)
		{
			result = -1;
			break;
		}

		vector<int> vec;

		if (r_cnt >= c_cnt)
		{
			for (int i = 1; i <= r_cnt; i++)
			{
				vector<info> temp;

				init();

				for (int j = 1; j <= c_cnt; j++)
				{
					visited[MAP[i][j]]++;
				}

				for (int j = 1; j <= 100; j++)
				{
					if (visited[j] != 0)
					{
						temp.push_back({ j, visited[j] });
					}
				}

				sort(temp.begin(), temp.end(), cmp);

				for (int j = 1; j <= c_cnt; j++)
				{
					MAP[i][j] = 0;
				}

				int idx = 1;

				for (int j = 0; j < temp.size(); j++)
				{
					MAP[i][idx] = temp[j].num;
					idx++;
					MAP[i][idx] = temp[j].cnt;
					idx++;
				}
				idx--;
				vec.push_back(idx);
			}
			sort(vec.begin(), vec.end());
			c_cnt = vec.back();
		}
		else
		{
			for (int i = 1; i <= c_cnt; i++)
			{
				vector<info> temp;

				init();

				for (int j = 1; j <= r_cnt; j++)
				{
					visited[MAP[j][i]]++;
				}

				for (int j = 1; j <= 100; j++)
				{
					if (visited[j] != 0)
					{
						temp.push_back({ j, visited[j] });
					}
				}

				sort(temp.begin(), temp.end(), cmp);

				for (int j = 1; j <= r_cnt; j++)
				{
					MAP[j][i] = 0;
				}

				int idx = 1;

				for (int j = 0; j < temp.size(); j++)
				{
					MAP[idx][i] = temp[j].num;
					idx++;
					MAP[idx][i] = temp[j].cnt;
					idx++;
				}
				idx--;
				vec.push_back(idx);
			}
			sort(vec.begin(), vec.end());
			r_cnt = vec.back();
		}
		time++;
	}
}

void solve()
{
	if (MAP[r][c] == k) return;
	else Find();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> MAP[i][j];
		}
	}

	solve();

	cout << result << "\n";

	return 0;
}