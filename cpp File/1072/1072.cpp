#include <iostream>

using namespace std;
typedef long long ll;

ll X, Y, Z, answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> X >> Y;

	Z = (Y * 100) / X;

	if (99 <= Z) answer = -1;
	else
	{
		ll start = 0;
		ll end = 1e9;

		while (start <= end)
		{
			ll mid = (start + end) >> 1;

			ll tempZ = ((Y + mid) * 100) / (X + mid);

			if (tempZ > Z)
			{
				answer = mid;
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}