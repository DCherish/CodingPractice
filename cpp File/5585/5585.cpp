#include <iostream>

using namespace std;

int coin[6] = { 500, 100, 50, 10, 5, 1 };

int cost;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> cost;

	cost = 1000 - cost;

	for (int i = 0; i < 6; i++)
	{
		if (cost >= coin[i])
		{
			cnt += (cost / coin[i]);
			cost %= coin[i];
		}
	}

	cout << cnt << "\n";

	return 0;
}