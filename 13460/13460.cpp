#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int mincnt = 777;
char matrix[10][10];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

class pnt
{
public:
	int x;
	int y;
};

pnt Red;
pnt Blue;

int Min(int A, int B)
{
	if (A < B) return A;
	else return B;
}

int Move_Dist(int x, int y, int xx, int yy)
{
	return abs(x - xx) + abs(y - yy);
}

int Inverse_Direction(int Cur_D)
{
	if (Cur_D == 0) return 1;
	else if (Cur_D == 1) return 0;
	else if (Cur_D == 2) return 3;
	else return 2;
}

void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir)
{
	if (Cnt >= mincnt) return;
	if (Cnt > 10) return;

	bool Red_Flag = false;
	bool Blue_Flag = false;

	int nRx = Rx + dx[dir];
	int nRy = Ry + dy[dir];

	while (true)
	{
		if (matrix[nRx][nRy] == '#') break;

		if (matrix[nRx][nRy] == 'O')
		{
			Red_Flag = true;
			break;
		}

		nRx = nRx + dx[dir];
		nRy = nRy + dy[dir];
	}

	nRx = nRx - dx[dir];
	nRy = nRy - dy[dir];

	int nBx = Bx + dx[dir];
	int nBy = By + dy[dir];

	while (1)
	{
		if (matrix[nBx][nBy] == '#') break;

		if (matrix[nBx][nBy] == 'O')
		{
			Blue_Flag = true;
			break;
		}

		nBx = nBx + dx[dir];
		nBy = nBy + dy[dir];
	}

	nBx = nBx - dx[dir];
	nBy = nBy - dy[dir];

	if (Blue_Flag == true) return;
	else
	{
		if (Red_Flag == true)
		{
			mincnt = Min(mincnt, Cnt);
			return;
		}
	}

	if (nRx == nBx && nRy == nBy)
	{
		int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy);
		int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);

		if (Red_Dist > Blue_Dist)
		{
			nRx = nRx - dx[dir];
			nRy = nRy - dy[dir];
		}
		else
		{
			nBx = nBx - dx[dir];
			nBy = nBy - dy[dir];
		}
	}


	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		if (i == Inverse_Direction(dir)) continue;

		Move(nRx, nRy, nBx, nBy, Cnt + 1, i);
	}
}

void Solution()
{
	for (int i = 0; i < 4; i++)
	{
		int x = Red.x;
		int y = Red.y;
		int xx = Blue.x;
		int yy = Blue.y;

		Move(x, y, xx, yy, 1, i);
	}

	if (mincnt > 10 || mincnt == 777) mincnt = -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];

			if (matrix[i][j] == 'R')
			{
				Red.x = i;
				Red.y = j;
				matrix[i][j] = '.';
			}

			else if (matrix[i][j] == 'B')
			{
				Blue.x = i;
				Blue.y = j;
				matrix[i][j] = '.';
			}
		}
	}

	Solution();

	cout << mincnt << "\n";

	return 0;
}