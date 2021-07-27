#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long tree[1000000];
long long maxlen;
long long ans;

bool is_valid(long long len)
{
	long long sum = 0;

	for (int i = 0; i < N; i++)
	{
		long long remain = tree[i] - len;

		if (remain > 0)
		{
			sum += remain;
		}
		else continue;
	}

	if (sum >= M) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];

		maxlen = max(maxlen, tree[i]);
	}

	long long start = 0;
	long long end = maxlen;

	while (start <= end)
	{
		long long mid = (start + end) / 2;

		if (is_valid(mid) == true)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}