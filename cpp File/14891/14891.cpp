#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

deque<char> DQ[4];
char DQ_temp[4];

char c;

int K, num, d;
int idx;

bool state[4];
char dir[4];

char l[4];
char r[4];

int score = 0;
int tempscore;

void check_l(int tempidx, char tempdir)
{
	char nextdir;

	if (tempidx < 0) return;

	if (tempdir == 'R')
	{
		nextdir = 'L';
	}
	else nextdir = 'R';

	if (r[tempidx] == l[tempidx + 1])
	{
		return;
	}
	else
	{
		check_l(tempidx - 1, nextdir);
		dir[tempidx] = tempdir;
		state[tempidx] = true;
	}
}

void check_r(int tempidx, char tempdir)
{
	char nextdir;

	if (tempidx > 3) return;

	if (tempdir == 'R')
	{
		nextdir = 'L';
	}
	else nextdir = 'R';

	if (l[tempidx] == r[tempidx - 1])
	{
		return;
	}
	else
	{
		check_r(tempidx + 1, nextdir);
		dir[tempidx] = tempdir;
		state[tempidx] = true;
	}
}

void lotate_l(int tempidx)
{
	DQ_temp[tempidx] = DQ[tempidx][0];

	DQ[tempidx].pop_front();
	DQ[tempidx].push_back(DQ_temp[tempidx]);
}

void lotate_r(int tempidx)
{
	DQ_temp[tempidx] = DQ[tempidx][7];

	DQ[tempidx].pop_back();
	DQ[tempidx].push_front(DQ_temp[tempidx]);
}

void func()
{
	idx = num - 1;

	for (int i = 0; i < 4; i++)
	{
		state[i] = false;
		dir[i] = 'N';

		l[i] = DQ[i][6];
		r[i] = DQ[i][2];
	}

	if (d == 1) // 시계 방향
	{
		state[idx] = true;
		dir[idx] = 'R';

		check_l(idx - 1, 'L');
		check_r(idx + 1, 'L');

		for (int j = 0; j < 4; j++)
		{
			if (state[j] == true)
			{
				if (dir[j] == 'R') lotate_r(j);
				else lotate_l(j);
			}
		}
	}
	else // 반시계 방향
	{
		state[idx] = true;
		dir[idx] = 'L';

		check_l(idx - 1, 'R');
		check_r(idx + 1, 'R');

		for (int j = 0; j < 4; j++)
		{
			if (state[j] == true)
			{
				if (dir[j] == 'R') lotate_r(j);
				else lotate_l(j);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> c;

			DQ[i].push_back(c);
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> num >> d;

		func();
	}

	for (int i = 0; i < 4; i++)
	{
		tempscore = pow(2, i);

		if (DQ[i][0] == '1') score += tempscore;
	}

	cout << score << "\n";

	return 0;
}