#include <iostream>

using namespace std;

int N, M;
char be_matrix[50][50];
char af_matrix[50][50];
int cnt = 0;

bool compare()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (be_matrix[i][j] != af_matrix[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void change(int a, int b)
{
	for (int i = a; i < a + 3; i++)
	{
		for (int j = b; j < b + 3; j++)
		{
			if (be_matrix[i][j] == '0')
			{
				be_matrix[i][j] = '1';
			}
			else be_matrix[i][j] = '0';
		}
	}
}

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
			cin >> be_matrix[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> af_matrix[i][j];
		}
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (be_matrix[i][j] != af_matrix[i][j])
			{
				change(i, j);
				cnt++;
			}
		}
	}

	if (compare() == true)
	{
		cout << cnt << "\n";
	}
	else
	{
		cout << "-1\n";
	}

	return 0;
}