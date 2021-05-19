#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a, b;
int arr[10001];

vector<int> node[10001];
bool visited[10001];
int dp[10001][2];

void solve(int idx)
{
	dp[idx][0] = 0;
	dp[idx][1] = arr[idx];

	for (int i = 0; i < node[idx].size(); i++)
	{
		int next = node[idx][i];

		if (visited[next] == false)
		{
			visited[next] = true;
			solve(next);

			dp[idx][0] += max(dp[next][0], dp[next][1]);
			dp[idx][1] += dp[next][0];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N - 1; i++)
	{
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}

	visited[1] = true;

	solve(1);

	cout << max(dp[1][0], dp[1][1]) << "\n";

	return 0;
}