#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, u, v;
vector<int> node[1000001];
bool visited[1000001];
int dp[1000001][2];

void solve(int idx)
{
	dp[idx][0] = 0;
	dp[idx][1] = 1;

	for (int i = 0; i < node[idx].size(); i++)
	{
		int next = node[idx][i];

		if (visited[next] == false)
		{
			visited[next] = true;
			solve(next);

			dp[idx][0] += dp[next][1];
			dp[idx][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N - 1; i++)
	{
		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	visited[1] = true;
	solve(1);

	cout << min(dp[1][0], dp[1][1]) << "\n";

	return 0;
}