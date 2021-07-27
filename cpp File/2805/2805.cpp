#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int tree[1000000];
int maxlen;
int ans;

bool is_valid(int len)
{
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int remain = tree[i] - len;

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

	int start = 0;
	int end = maxlen;

	while (start <= end)
	{
		int mid = (start + end) / 2;

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