#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int N;
int result;
bool state1, state2;

void solve()
{
	for (int i = N; i <= 2000000; i++)
	{
		if (i <= 1) continue;

		state1 = true;
		int idx = sqrt(i);

		for (int j = 2; j <= idx; j++)
		{
			if (i % j == 0)
			{
				state1 = false;
				break;
			}
		}

		if (state1 == true)
		{
			string str = to_string(i);
			int len = str.length();
			state2 = true;

			for (int j = 0; j < len / 2; j++)
			{
				if (str[j] != str[len - 1 - j])
				{
					state2 = false;
					break;
				}
			}

			if (state2 == true)
			{
				result = i;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	solve();

	cout << result << "\n";

	return 0;
}