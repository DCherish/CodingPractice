#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	int x;
	int y;
};

int N, r, c;

vector<info> vec;

long long ans = LLONG_MAX;

void solve(int depth, int idx, long long score)
{
	if (idx < 0 || idx >= N) return;

	if (depth == N)
	{
		ans = min(ans, score);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> r >> c;

		vec.push_back({r, c});
	}

	for (int i = 0; i < N; i++)
	{
		solve(0, i, 0);
	}

	return 0;
}