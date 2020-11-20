#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, c;
vector<int> coin;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> c;

		coin.push_back(c);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (K / coin[i] > 0)
		{
			cnt += K / coin[i];

			K = K % coin[i];
		}

		if (K == 0) break;
	}

	cout << cnt << "\n";

	return 0;
}