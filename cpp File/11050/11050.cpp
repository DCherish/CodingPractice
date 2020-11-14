#include <iostream>

using namespace std;

int N, K;
int arr[11][11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	if (N / 2 < K) // 최적화
	{
		K = N - K;
	}

	for (int i = 1; i <= N; i++)
	{
		arr[i][0] = 1;
		arr[i][1] = i;

		for (int j = 2; j <= K; j++)
		{
			if (j > i) break; // 최적화
			else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cout << arr[N][K] << "\n";

	return 0;
}