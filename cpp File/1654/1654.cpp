#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
long long arr[10000];
long long ans, max_len;

bool is_valid(long long len)
{
	int cnt = 0;

	for (int i = 0; i < K; i++)
	{
		cnt += arr[i] / len;
	}

	if (cnt >= N) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];

		max_len = max(max_len, arr[i]);
	}

	long long start = 1;
	long long end = max_len;

	while (start <= end)
	{
		long long mid = (start + end) / 2; // start + end 가 int를 초과할 수 있음, 따라서 long long

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