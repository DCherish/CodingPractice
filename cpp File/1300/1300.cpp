#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, k;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> k;

	int start = 1;
	int end = k;

	int ans = -1;

	while (start <= end)
	{
		int cnt = 0;

		int mid = (start + end) / 2;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(mid / i, N);
		}

		if (cnt < k)
		{
			start = mid + 1;
		}
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}