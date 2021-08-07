#include <iostream>
#include <cmath>
#define MAX 1000000000

using namespace std;
typedef long long ll;

ll X, Y;
int prev_rate;

int ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> X >> Y;

	prev_rate = Y * 100 / X;

	if (prev_rate >= 99)
	{
		cout << -1 << "\n";
	}
	else
	{
		int l = 0;
		int r = MAX;

		while (l <= r)
		{
			int mid = (l + r) / 2;

			int temp_rate = ((Y + mid) * 100) / (X + mid);

			if (prev_rate >= temp_rate)
			{
				ans = mid + 1;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		cout << ans << "\n";
	}

	return 0;
}