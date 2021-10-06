#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M, answer;
int L = INT_MAX;
int R = 0;
int arr[100001];
int arrsum[100001];

bool check(int idx)
{
	int prev = 0;
	int next = 1;
	int cnt = 0;

	while (next <= N)
	{
		if (arrsum[next] - arrsum[prev] > idx)
		{
			if (prev + 1 == next) return false;

			prev = next - 1;
			cnt++;
		}
		else next++;
	}

	if (cnt + 1 <= M) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		R += arr[i];

		arrsum[i] += arrsum[i - 1] + arr[i];

		L = min(L, arr[i]);
	}

	while (L <= R)
	{
		int mid = (L + R) >> 1;

		if (check(mid))
		{
			answer = mid;
			R = mid - 1;
		}
		else L = mid + 1;
	}

	cout << answer << "\n";

	return 0;
}