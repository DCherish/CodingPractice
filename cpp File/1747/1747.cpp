#include <iostream>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

bool prime[2000001];
int N;

void setPrime()
{
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(2e6); i++)
	{
		if (!prime[i]) continue;

		for (int j = i * i; j <= 2e6; j += i)
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

	setPrime();

	cin >> N;

	for (int i = N; i <= 2e6; i++)
	{
		if (prime[i])
		{
			string str = to_string(i);
			bool state = true;

			for (int j = 0; j < str.length() / 2; j++)
			{
				if (str[j] != str[str.length() - 1 - j])
				{
					state = false;
					break;
				}
			}

			if (state)
			{
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}