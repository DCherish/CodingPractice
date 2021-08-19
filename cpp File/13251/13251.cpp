#include <iostream>

using namespace std;

int M, K, total;
int arr[51];
double ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];

		total += arr[i];
	}

	cin >> K;

	for (int i = 0; i < M; i++)
	{
		double temp = 1.0;

		if (K > arr[i]) continue;

		for (int j = 0; j < K; j++)
		{
			temp *= ((double)arr[i] - (double)j) / ((double)total - (double)j);
		}

		ans += temp;
	}

	cout << fixed;
	cout.precision(12);

	cout << ans << "\n";

	return 0;
}