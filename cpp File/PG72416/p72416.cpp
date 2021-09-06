#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int dp[300001][2];

vector<int> Node[300001];
vector<int> cost;

void DFS(int idx)
{
	bool leaf = true;

	for (int i = 0; i < Node[idx].size(); i++)
	{
		int child = Node[idx][i];
		leaf = false;
		DFS(child);
	}

	if (leaf == true)
	{
		dp[idx][0] = 0;
		dp[idx][1] = cost[idx];
		return;
	}

	int sum = 0;
	int mincost = INT_MAX;
	bool attend = true;

	for (int i = 0; i < Node[idx].size(); i++)
	{
		int child = Node[idx][i];
		sum += min(dp[child][0], dp[child][1]);

		if (dp[child][0] >= dp[child][1]) attend = false;
		mincost = min(mincost, dp[child][1] - dp[child][0]);
	}

	dp[idx][1] = cost[idx] + sum;

	if (attend == false) dp[idx][0] = sum;
	else dp[idx][0] = sum + mincost;
}

int solution(vector<int> sales, vector<vector<int>> links)
{
	int answer = 0;

	cost.resize(sales.size() + 1);

	for (int i = 1; i <= sales.size(); i++)
	{
		cost[i] = sales[i - 1];
	}

	for (int i = 0; i < links.size(); i++)
	{
		int parent = links[i][0];
		int child = links[i][1];

		Node[parent].push_back(child);
	}

	DFS(1);

	answer = min(dp[1][0], dp[1][1]);

	return answer;
}