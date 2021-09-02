#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 987654321

using namespace std;

int n, ans;
int cost[5][5];
int dp[100001][5][5];

vector<int> cmd;

int solve(int depth, int left, int right)
{
	if (depth == cmd.size()) return 0;
	if ((left != 0 && right != 0) && left == right) return MAX;

	int& value = dp[depth][left][right];
	if (value != -1) return value;

	return value = min(solve(depth + 1, cmd[depth], right) + cost[left][cmd[depth]], solve(depth + 1, left, cmd[depth]) + cost[right][cmd[depth]]);
}

void pre_setting()
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (i == 0)
			{
				cost[i][j] = 2;
			}
			else
			{
				if (i == j) cost[i][j] = 1;
				else if (abs(i - j) == 2) cost[i][j] = 4;
				else cost[i][j] = 3;
			}
		}
	}

	memset(dp, -1, sizeof(dp));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pre_setting();

	while (cin >> n)
	{
		if (n == 0) break;
		else cmd.push_back(n);
	}

	cout << solve(0, 0, 0) << "\n";

	return 0;
}