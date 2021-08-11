#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;
bool prime[1001];

vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	memset(prime, true, sizeof(prime));

	for (int i = 2; i <= N; i++)
	{
		if (prime[i] == false) continue;

		vec.push_back(i);

		for (int j = i + i; j <= N; j = j + i)
		{
			if (prime[j] == false) continue;

			prime[j] = false;

			vec.push_back(j);
		}
	}

	cout << vec[K - 1] << "\n";

	return 0;
}