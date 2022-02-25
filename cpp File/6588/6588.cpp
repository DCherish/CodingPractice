#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool prime[1000001];

int n;

void setPrime()
{
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(1e6); i++)
	{
		if (!prime[i]) continue;

		for (int j = i * i; j <= 1e6; j += i)
		{
			prime[j] = false;
		}
	}
}

int isPrime(int idx)
{
	for (int i = 3; i <= idx / 2; i += 2)
	{
		if (!prime[i]) continue;

		if (prime[idx - i]) return i;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	setPrime();

	for (;;)
	{
		cin >> n;

		if (0 == n) break;

		int state = isPrime(n);

		if (-1 != state)
		{
			cout << n << " = " << state << " + " << n - state << "\n";
		}
		else
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}