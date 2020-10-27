#include <iostream>

using namespace std;

int matrix[1001][10] = { 0, };

int N;
int sum = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < 10; i++)
	{
		matrix[1][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		matrix[i][0] = 1;

		for (int j = 1; j < 10; j++)
		{
			matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
			matrix[i][j] = matrix[i][j] % 10007;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		sum = sum + matrix[N][i];
		sum = sum % 10007;
	}

	cout << sum << "\n";

	return 0;
}