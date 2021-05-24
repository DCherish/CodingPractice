#include <iostream>

using namespace std;

int R, C, T;
int A[50][50];
int S[50][50];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int c_x = 0;
int answer = 0;

void Clean()
{
	int idx = c_x;

	for (int i = idx - 1; i >= 1; i--)
	{
		A[i][0] = A[i - 1][0];
	}

	for (int i = 0; i <= C - 2; i++)
	{
		A[0][i] = A[0][i + 1];
	}

	for (int i = 0; i <= idx - 1; i++)
	{
		A[i][C - 1] = A[i + 1][C - 1];
	}

	for (int i = C - 1; i >= 2; i--)
	{
		A[idx][i] = A[idx][i - 1];
	}

	A[idx][1] = 0;

	idx++;

	for (int i = idx + 1; i <= R - 2; i++)
	{
		A[i][0] = A[i + 1][0];
	}

	for (int i = 0; i <= C - 2; i++)
	{
		A[R - 1][i] = A[R - 1][i + 1];
	}

	for (int i = R - 1; i >= idx + 1; i--)
	{
		A[i][C - 1] = A[i - 1][C - 1];
	}

	for (int i = C - 1; i >= 2; i--)
	{
		A[idx][i] = A[idx][i - 1];
	}

	A[idx][1] = 0;
}

void Spread()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] != 0 && A[i][j] != -1)
			{
				int value = A[i][j] / 5;
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (A[nx][ny] == -1) continue;

					S[nx][ny] += value;
					cnt++;
				}

				S[i][j] += A[i][j] - cnt * value;
			}
			else if (A[i][j] == -1)
			{
				S[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			A[i][j] = S[i][j];
			S[i][j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> A[i][j];

			if (A[i][j] == -1 && c_x == 0)
			{
				c_x = i;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		Spread();
		Clean();
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] != -1)
			{
				answer += A[i][j];
			}
		}
	}

	cout << answer << "\n";

	return 0;
}