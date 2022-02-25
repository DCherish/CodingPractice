#include <iostream>
#include <cstring>
#include <cmath>
#define MAX (int)1e6

using namespace std;

bool prime[MAX];
int M, N;

void setPrime()
{
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (!prime[i]) continue;

		for (int j = i * i; j <= N; j += i)
		{
			prime[j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	setPrime();

	for (int i = M; i <= N; i++)
	{
		if (prime[i]) cout << i << "\n";
	}

	return 0;
}