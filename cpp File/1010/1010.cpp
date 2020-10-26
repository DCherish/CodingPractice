#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M;

int DP[31][31] = { 0, };

vector<int> answer;

void cal()
{
	for (int a = 0; a <= 30; a++)
	{
		DP[a][0] = 1;
		DP[a][a] = 1;

		for (int b = 1; b <= a - 1; b++)
		{
			DP[a][b] = DP[a - 1][b - 1] + DP[a - 1][b];
		}
	}
}

int main()
{
	cin >> T;

	cal();

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		answer.push_back(DP[M][N]);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}