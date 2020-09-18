#include <iostream>
#include <algorithm>

using namespace std;

char bfmatrix[100][100];
char afmatrix[100][100];

int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> bfmatrix[i][j];

			if (bfmatrix[i][j] == '-')
			{
				afmatrix[M-j-1][i] = '|';
			}else if (bfmatrix[i][j] == '|')
			{
				afmatrix[M-j-1][i] = '-';
			}else if (bfmatrix[i][j] == '/')
			{
				afmatrix[M-j-1][i] = (char)92;
			}else if (bfmatrix[i][j] == (char)92)
			{
				afmatrix[M-j-1][i] = '/';
			}else if (bfmatrix[i][j] == '^')
			{
				afmatrix[M-j-1][i] = '<';
			}else if (bfmatrix[i][j] == '<')
			{
				afmatrix[M-j-1][i] = 'v';
			}else if (bfmatrix[i][j] == 'v')
			{
				afmatrix[M-j-1][i] = '>';
			}else if (bfmatrix[i][j] == '>')
			{
				afmatrix[M-j-1][i] = '^';
			}
			else
			{
				afmatrix[M-j-1][i] = bfmatrix[i][j];
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << afmatrix[i][j];
		}
		cout << "\n";
	}
}