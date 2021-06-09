#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct t_info
{
	int x;
	int y;
	int empty_cnt;
	int like_cnt;
};

int N, num, a, b, c, d;
int answer = 0;

deque<int> student_wait;
vector<int> student_info[401];
vector<t_info> vec;

int MAP[20][20];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(t_info a, t_info b)
{
	if (a.like_cnt == b.like_cnt)
	{
		if (a.empty_cnt == b.empty_cnt)
		{
			if (a.x == b.x)
			{
				return a.y < b.y;
			}
			else return a.x < b.x;
		}
		else return a.empty_cnt > b.empty_cnt;
	}
	else return a.like_cnt > b.like_cnt;
}

void calc(int idx)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] != 0) continue;

			int empty_cnt = 0;
			int like_cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (MAP[nx][ny] == 0) empty_cnt++;
				else
				{
					for (int p = 0; p < 4; p++)
					{
						if (MAP[nx][ny] == student_info[idx][p])
						{
							like_cnt++;
							break;
						}
					}
				}
			}

			vec.push_back({ i, j, empty_cnt, like_cnt });
		}
	}
}

void solve()
{
	while (!student_wait.empty())
	{
		int idx = student_wait.front();
		student_wait.pop_front();

		vec.clear();

		calc(idx);

		sort(vec.begin(), vec.end(), cmp);

		MAP[vec[0].x][vec[0].y] = idx;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		cin >> num >> a >> b >> c >> d;

		student_info[num].push_back(a);
		student_info[num].push_back(b);
		student_info[num].push_back(c);
		student_info[num].push_back(d);

		student_wait.push_back(num);
	}

	solve();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp_idx = MAP[i][j];
			int temp_cnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				for (int p = 0; p < 4; p++)
				{
					if (MAP[nx][ny] == student_info[temp_idx][p])
					{
						temp_cnt++;
						break;
					}
				}
			}

			if (temp_cnt == 1)
			{
				answer += 1;
			}
			else if (temp_cnt == 2)
			{
				answer += 10;
			}
			else if (temp_cnt == 3)
			{
				answer += 100;
			}
			else if (temp_cnt == 4)
			{
				answer += 1000;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}