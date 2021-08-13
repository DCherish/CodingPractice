#include <iostream>

using namespace std;

int X, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> X;

	while (X > 0)
	{
		if (X & 1) ans++;

		X >>= 1;
	}

	cout << ans << "\n";

	return 0;
}