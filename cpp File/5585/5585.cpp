#include <iostream>

using namespace std;

int N;
int coin[6] = { 500, 100, 50, 10, 5, 1 };
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	N = 1000 - N;

	for (int i = 0; i < 6; i++)
	{
		if (N / coin[i] > 0)
		{
			cnt += N / coin[i];

			N = N % coin[i];
		}

		if (N == 0) break;
	}

	cout << cnt << "\n";

	return 0;
}