#include <iostream>
#include <vector>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int T, N;
int matrix[2][100000] = { 0, };
int plusmtx[2][100000] = { 0, } ;

int result;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> matrix[j][k];
			}
		}

		plusmtx[0][0] = matrix[0][0];
		plusmtx[1][0] = matrix[1][0];
		plusmtx[0][1] = matrix[1][0] + matrix[0][1];
		plusmtx[1][1] = matrix[0][0] + matrix[1][1];

		for (int a = 2; a < N; a++)
		{
			int tempM = Max(plusmtx[0][a - 2], plusmtx[1][a - 2]);

			for (int b = 0; b < 2; b++)
			{
				int idx = (b + 1) % 2;
				plusmtx[b][a] = Max(plusmtx[idx][a - 1] + matrix[b][a], tempM + matrix[b][a]);
			}
		}

		result = Max(plusmtx[0][N - 1], plusmtx[1][N - 1]);

		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}