#include <iostream>
#include <cstring>

using namespace std;

bool prime[1001];

int N, K, cnt;

bool state = false;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	cin >> N >> K;

	for (int i = 2; i <= N; i++)
	{
		if (!prime[i]) continue;

		for (int j = i; j <= N; j = j + i)
		{
			if (prime[j])
			{
				prime[j] = false;

				if (K == ++cnt)
				{
					cout << j << "\n";
					state = true;

					break;
				}
			}
		}

		if (state) break;
	}

	return 0;
}