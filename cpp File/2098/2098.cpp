#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 16
#define INF 987654321

using namespace std;

int N, ans_bit;
int W[MAX][MAX];
int cost[MAX][1 << MAX];

int DFS(int c_node, int c_bit)
{
	if (c_bit == ans_bit)
	{
		if (W[c_node][0] == 0) return INF;
		else return W[c_node][0];
	}

	if (cost[c_node][c_bit] != -1) return cost[c_node][c_bit];
	cost[c_node][c_bit] = INF;

	for (int i = 0; i < N; i++)
	{
		if (W[c_node][i] == 0) continue;
		if ((c_bit & (1 << i)) == (1 << i)) continue;

		cost[c_node][c_bit] = min(cost[c_node][c_bit], W[c_node][i] + DFS(i, c_bit | (1 << i)));
	}

	return cost[c_node][c_bit];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	ans_bit = (1 << N) - 1;

	memset(cost, -1, sizeof(cost));

	cout << DFS(0, 1) << "\n";

	return 0;
}