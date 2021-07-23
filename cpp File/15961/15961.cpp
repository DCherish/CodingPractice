#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N, d, k, c, ans, cnt;

int sushi[3000000];
int sushi_kind[3001];

deque<int> DQ;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
	{
		cin >> sushi[i];
	}

	for (int i = 0; i < k; i++)
	{
		DQ.push_back(sushi[i]);
		sushi_kind[sushi[i]]++;

		if (sushi_kind[sushi[i]] == 1) cnt++;

		ans = max(ans, cnt);
	}

	for (int i = 0; i < N - 1; i++)
	{
		DQ.pop_front();
		sushi_kind[sushi[i]]--;

		if (sushi_kind[sushi[i]] == 0) cnt--;

		DQ.push_back(sushi[(i + k) % N]);
		sushi_kind[sushi[(i + k) % N]]++;

		if (sushi_kind[sushi[(i + k) % N]] == 1) cnt++;

		if (sushi_kind[c] == 0)
		{
			ans = max(ans, cnt + 1);
		}
		else
		{
			ans = max(ans, cnt);
		}
	}

	cout << ans << "\n";

	return 0;
}