#include <iostream>
#include <vector>

using namespace std;

int C, N;
int cnt[1001];

vector<int> ans;

int gcd(int x, int y)
{
	if (x < y)
	{
		int temp = x;
		x = y;
		y = temp;
	}

	while (true)
	{
		if (x % y == 0) return y;

		int temp = x % y;
		x = y;
		y = temp;
	}
}

void cal()
{
	cnt[0] = 0;
	cnt[1] = 2;

	for (int i = 2; i <= 1000; i++)
	{
		int a = 0;

		for (int j = 1; j <= i; j++)
		{
			if (gcd(i, j) == 1) a++;
		}

		cnt[i] = cnt[i - 1] + a;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cal();

	cin >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> N;

		ans.push_back(cnt[N] * 2 - 1);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}