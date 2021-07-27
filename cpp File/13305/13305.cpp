#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long dist[100000];
long long cost[100000];

long long mincost, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> dist[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];
	}

	mincost = cost[0];

	for (int i = 0; i < N - 1; i++)
	{
		mincost = min(mincost, cost[i]);

		ans += mincost * dist[i];
	}

	cout << ans << "\n";

	return 0;
}