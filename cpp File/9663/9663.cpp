#include <iostream>

using namespace std;
typedef long long ll;

int N, ans;
int col[15];

bool check(int r1, int c1, int r2, int c2)
{
	if (c1 == c2) return true;
	if (r1 - c1 == r2 - c2) return true;
	if (r1 + c1 == r2 + c2) return true;
	return false;
}

void solve(int row)
{
	if (row == N + 1)
	{
		ans++;
	}
	else
	{
		for (int c = 1; c <= N; c++)
		{
			bool possible = true;

			for (int i = 1; i <= row - 1; i++)
			{
				if (check(row, c, i, col[i]) == true)
				{
					possible = false;
					break;
				}
			}

			if (possible == true)
			{
				col[row] = c;
				solve(row + 1);
				col[row] = 0;
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

	solve(1);

	cout << ans << "\n";

	return 0;
}