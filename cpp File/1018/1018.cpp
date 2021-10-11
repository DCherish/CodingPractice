#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int R, C, cnt;
char MAP[50][50];

void check(int x, int y)
{
	int tempcnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 != 0)
			{
				if (MAP[x][y] == MAP[x + i][y + j]) tempcnt++;
			}
			else
			{
				if (MAP[x][y] != MAP[x + i][y + j]) tempcnt++;
			}
		}
	}

	if (tempcnt > 32) tempcnt = 64 - tempcnt;

	cnt = min(cnt, tempcnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> MAP[i][j];
		}
	}

	cnt = INT_MAX;

	for (int i = 0; i <= R - 8; i++)
	{
		for (int j = 0; j <= C - 8; j++)
		{
			check(i, j);
		}
	}

	cout << cnt << endl;

	return 0;
}