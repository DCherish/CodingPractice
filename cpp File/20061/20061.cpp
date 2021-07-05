#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	int s;
	int x;
	int y;
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N, a, b, c;
vector<info> vec;
int MAP[10][4][2];

int b_cnt = 0;
int score = 0;
int f_num = 1;

void rm(int idx, int color)
{
	for (int i = 0; i < 4; i++)
	{
		if (MAP[idx][i][color] != 0)
		{
			b_cnt--;
			MAP[idx][i][color] = 0;
		}
	}
}

void mv(int idx, int color)
{
	if (idx == 3) return;

	int m_idx = idx - 1;

	for (int i = 0; i < 4; i++)
	{
		MAP[idx][i][color] = MAP[m_idx][i][color];
		MAP[m_idx][i][color] = 0;
	}

	mv(idx - 1, color);
}

void setting_block(int shape, int x, int y)
{
	if (shape == 1) // .
	{
		int b_idx = y + 1;
		while (b_idx < 10 && MAP[b_idx][x][0] == 0) b_idx++;
		MAP[b_idx - 1][x][0] = f_num;

		int g_idx = x + 1;
		while (g_idx < 10 && MAP[g_idx][y][1] == 0) g_idx++;
		MAP[g_idx - 1][y][1] = f_num;

		f_num++;

		b_cnt += 2;
	}
	else if (shape == 2) // คั
	{
		int b_idx = y + 2;
		while (b_idx < 10 && MAP[b_idx][x][0] == 0) b_idx++;
		MAP[b_idx - 2][x][0] = f_num;
		MAP[b_idx - 1][x][0] = f_num;

		int g_idx = x + 1;
		while (g_idx < 10 && MAP[g_idx][y][1] == 0 && MAP[g_idx][y + 1][1] == 0) g_idx++;
		MAP[g_idx - 1][y][1] = f_num;
		MAP[g_idx - 1][y + 1][1] = f_num;

		f_num++;

		b_cnt += 4;
	}
	else // คำ
	{
		int b_idx = y + 1;
		while (b_idx < 10 && MAP[b_idx][x][0] == 0 && MAP[b_idx][x + 1][0] == 0) b_idx++;
		MAP[b_idx - 1][x][0] = f_num;
		MAP[b_idx - 1][x + 1][0] = f_num;

		int g_idx = x + 2;
		while (g_idx < 10 && MAP[g_idx][y][1] == 0) g_idx++;
		MAP[g_idx - 2][y][1] = f_num;
		MAP[g_idx - 1][y][1] = f_num;

		f_num++;

		b_cnt += 4;
	}
}

void remove_full_block()
{
	bool state = false;

	for (int color = 0; color < 2; color++)
	{
		for (int i = 9; i >= 6; i--)
		{
			int cnt = 0;

			for (int j = 0; j < 4; j++)
			{
				if (MAP[i][j][color] != 0) cnt++;
			}

			if (cnt == 4)
			{
				state = true;
				score++;
				rm(i, color);
				mv(i, color);

				break;
			}
		}
	}

	if (state == true) remove_full_block();
}

void check_special_point()
{
	for (int color = 0; color < 2; color++)
	{
		int cnt = 0;

		for (int sp = 4; sp < 6; sp++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (MAP[sp][i][color] != 0)
				{
					cnt++;
					break;
				}
			}
		}

		if (cnt != 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				rm(9, color);
				mv(9, color);
			}
		}
	}
}

void solve()
{
	for (int i = 0; i < vec.size(); i++)
	{
		int s = vec[i].s;
		int x = vec[i].x;
		int y = vec[i].y;

		setting_block(s, x, y);
		remove_full_block();
		check_special_point();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		vec.push_back({ a, b, c });
	}

	solve();

	cout << score << "\n";
	cout << b_cnt << "\n";

	return 0;
}