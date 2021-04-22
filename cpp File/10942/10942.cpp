#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001];
int result;

vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		dp[i][i] = true;

		if (arr[i - 1] == arr[i])
		{
			dp[i - 1][i] = true;
		}
	}

	for (int gap = 2; gap < N; gap++)
	{
		for (int k = 1; k <= N - gap; k++)
		{
			int idx = k + gap;

			if (arr[k] == arr[idx] && dp[k + 1][idx - 1] == true)
			{
				dp[k][idx] = true;
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int S, E;

		cin >> S >> E;

		if (dp[S][E] == true) result = 1;
		else result = 0;

		answer.push_back(result);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}