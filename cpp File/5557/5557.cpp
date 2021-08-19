#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int N;

int arr[110];
ll DP[110][30];

void cal(int x)
{
	if (x == N) return;

	for (int i = 0; i <= 20; i++)
	{
		if (DP[x - 1][i] != 0)
		{
			if (i + arr[x] <= 20)
			{
				DP[x][i + arr[x]] += DP[x - 1][i];
			}

			if (i - arr[x] >= 0)
			{
				DP[x][i - arr[x]] += DP[x - 1][i];
			}
		}
	}
}

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

	DP[1][arr[1]] = 1;

	for (int i = 2; i < N; i++)
	{
		cal(i);
	}

	cout << DP[N - 1][arr[N]] << "\n";

	return 0;
}