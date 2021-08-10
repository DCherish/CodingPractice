#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;
typedef long long ll;

bool state = false;

int N;
ll minsum = LLONG_MAX;
ll ans[3];

vector<ll> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		ll a;
		cin >> a;

		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), less<ll>());

	for (int i = 0; i < N - 2; i++)
	{
		int l = i + 1;
		int r = N - 1;

		while (l < r)
		{
			ll sum = vec[i] + vec[l] + vec[r];

			if (abs(sum) < minsum)
			{
				minsum = abs(sum);

				ans[0] = vec[i];
				ans[1] = vec[l];
				ans[2] = vec[r];
			}

			if (sum == 0)
			{
				state = true;
				break;
			}

			if (sum < 0) l++;
			else r--;
		}

		if (state == true) break;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << " ";
	}

	cout << "\n";

	return 0;
}