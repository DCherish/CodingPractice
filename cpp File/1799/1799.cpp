#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int sz;
int matrix[10][10];

int cv;

int bmax = 0;
int wmax = 0;

int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };

bool CrossSearch(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < sz; j++)
		{
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			if (nx < 0 || ny < 0 || nx >= sz || ny >= sz) break;
			if (matrix[nx][ny] == 0) continue;
			if (matrix[nx][ny] == 2) return false;
		}
	}
	return true;
}

void CrossSet(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < sz; j++)
		{
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			if (nx < 0 || ny < 0 || nx >= sz || ny >= sz) break;
			if (matrix[nx][ny] == 0) continue;
			if (matrix[nx][ny] == 1) matrix[nx][ny] = -1;
		}
	}
}

void CrossReset(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < sz; j++)
		{
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;

			if (nx < 0 || ny < 0 || nx >= sz || ny >= sz) break;
			if (matrix[nx][ny] == 0) continue;
			if (matrix[nx][ny] == -1)
			{
				if (CrossSearch(nx, ny) == true) matrix[nx][ny] = 1;
				else matrix[nx][ny] = -1;
			}
		}
	}
}

void DFS(int x, int y, int cnt, int color)
{
	if ( color == 0 )
	{
		if (cnt > bmax) bmax = cnt;
	}else
	{
		if (cnt > wmax) wmax = cnt;
	}

	for (int i = x; i < sz; i++)
	{
		if (color == 0 && y == 0)
		{
			cv = i % 2;
		}else if (color == 1 && y == 0)
		{
			cv = (i + 1) % 2;
		}else
		{
			cv = 0;
		}

		for (int j = y + cv; j < sz; j = j + 2)
		{
			if (matrix[i][j] == 1)
			{
				matrix[i][j] = 2;
				CrossSet(i, j);
				DFS(i, j + 2, cnt + 1, color);
				matrix[i][j] = 1;
				CrossReset(i, j);
			}
		}
		y = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> sz;

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			cin >> matrix[i][j];
		}
	}

	DFS(0, 0, 0, 0);
	DFS(0, 0, 0, 1);

	cout << bmax + wmax << "\n";

	return 0;
}

//#include<iostream>
//#define max(a,b) a > b ? a : b
//using namespace std;
//
//int N;
//int ans[2];
//int chess[11][11];
//int l[20];
//int r[20];
//
//// 놓을 수 있는 비숍의 최대개수를 구하는 함수
//// 흑/백, 두 가지 경우로 나누어 계산
//
//void tracking(int row, int col, int count, int color)
//{
//	if (col >= N) {
//		row++;
//		if(col%2 == 0) col = 1;
//		else col = 0;
//	}
//	if (row >= N) {
//		ans[color] = max(ans[color], count);
//		return;
//	}
//
//	if (chess[row][col] && !l[col - row + N - 1] && !r[row + col])
//	{
//		l[col - row + N - 1] = r[row + col] = 1;
//		tracking(row, col+2, count + 1, color);
//		l[col - row + N - 1] = r[row + col] = 0;
//	}
//	tracking(row, col+2, count, color);
//}
//
//int main(void)
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> chess[i][j];
//		}
//	}
//
//	tracking(0, 0, 0, 0);
//	tracking(0, 1, 0, 1);
//
//	cout << ans[0] + ans[1];
//
//	return 0;
//}
