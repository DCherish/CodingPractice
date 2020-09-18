#include <iostream>
#include <algorithm>

using namespace std;

int matrix[10][10];
bool row_v[10][10] = { false, };
bool col_v[10][10] = { false, };
bool sqr_v[10][10] = { false, };

void printMatrix()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void Function(int cnt)
{
	if (cnt == 82)
	{
		printMatrix();
		exit(0);
	}

	int tx = (cnt - 1) / 9 + 1;
	int ty = (cnt - 1) % 9 + 1;

	int temp = (tx - 1) / 3;
	int tempbigsqrNum = 3 * temp + ((ty - 1) / 3) + 1;

	if (matrix[tx][ty] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (row_v[tx][i] == false && col_v[ty][i] == false && sqr_v[tempbigsqrNum][i] == false)
			{
				row_v[tx][i] = true;
				col_v[ty][i] = true;
				sqr_v[tempbigsqrNum][i] = true;
				matrix[tx][ty] = i;
				Function(cnt + 1);
				matrix[tx][ty] = 0;
				sqr_v[tempbigsqrNum][i] = false;
				col_v[ty][i] = false;
				row_v[tx][i] = false;
			}
		}
	}
	else Function(cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> matrix[i][j];

			int temp = (i - 1) / 3;
			int bigsqrNum = 3 * temp + ((j - 1) / 3) + 1;

			if (matrix[i][j] != 0)
			{
				row_v[i][matrix[i][j]] = true;
				col_v[j][matrix[i][j]] = true;
				sqr_v[bigsqrNum][matrix[i][j]] = true;
			}
		}
	}

	Function(1);

	return 0;
}