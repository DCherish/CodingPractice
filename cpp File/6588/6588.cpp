#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 1000000

using namespace std;

struct info
{
	int num;
	int x;
	int y;
};

int n;
bool prime[1000001];

vector<info> ans;

void cal_prime()
{
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (prime[i] == false) continue;

		for (int j = i * i; j <= MAX; j = j + i)
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

	cal_prime();

	while (cin >> n)
	{
		if (n == 0) break;

		bool state = false;

		for (int i = 3; i <= n; i = i + 2)
		{
			if (prime[i] == true && prime[n - i] == true)
			{
				ans.push_back({ n, i, n - i });
				state = true;
				break;
			}
		}

		if (state == false)
		{
			ans.push_back({ -1, -1, -1 });
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].num == -1)
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
		else
		{
			cout << ans[i].num << " = " << ans[i].x << " + " << ans[i].y << "\n";
		}
	}

	return 0;
}