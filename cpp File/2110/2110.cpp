#include <iostream>
#include <algorithm>

using namespace std;

int N, C, ans;
int house[200000];

bool is_valid(int dist)
{
	int cnt = 1;
	int prev = house[0];

	for (int i = 1; i < N; i++)
	{
		if (house[i] - prev >= dist)
		{
			cnt++;
			prev = house[i];
		}
	}

	if (cnt >= C) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}

	sort(house, house + N, less<int>());

	int low = 1; // 최소 거리
	int high = house[N - 1] - house[0]; // 최대 거리

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (is_valid(mid) == true)
		{
			ans = max(ans, mid);
			low = mid + 1;
		}
		else high = mid - 1;
	}

	cout << ans << "\n";
	return 0;
}