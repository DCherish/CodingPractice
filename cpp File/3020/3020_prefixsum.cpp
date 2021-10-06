#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H, d, u;
int idx, cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> H;

	idx = N;
	cnt = 0;

	vector<int> bottom(H + 1);
	vector<int> top(H + 1);

	for (int i = 0; i < N / 2; i++)
	{
		cin >> d >> u;

		bottom[d] += 1;
		top[u] += 1;
	}

	for (int i = H - 1; i >= 0; i--)
	{
		bottom[i] += bottom[i + 1];
		top[i] += top[i + 1];
	}

	for (int i = 1; i < H + 1; i++)
	{
		if (idx > bottom[i] + top[H - i + 1])
		{
			idx = bottom[i] + top[H - i + 1];
			cnt = 1;
		}
		else if (idx == bottom[i] + top[H - i + 1])
		{
			cnt++;
		}
	}

	cout << idx << " " << cnt << "\n";

	return 0;
}