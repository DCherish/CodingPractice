#include <iostream>
#include <vector>
#include <queue>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int N;
int cost[10000];
int result[10000];
int cnt, num;

int pre[10000];
vector<int> post[10000];
queue<int> Q;

int mincost;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cost[i];

		cin >> cnt;

		for (int j = 0; j < cnt; j++)
		{
			cin >> num;

			pre[i]++;
			post[num - 1].push_back(i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		result[i] = cost[i];

		if (result[i] > mincost)
		{
			mincost = result[i];
		}

		if (pre[i] == 0)
		{
			Q.push(i);
		}
	}

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		for (int i = 0; i < post[idx].size(); i++)
		{
			result[post[idx][i]] = Max(result[post[idx][i]], result[idx] + cost[post[idx][i]]);

			if (result[post[idx][i]] > mincost)
			{
				mincost = result[post[idx][i]];
			}

			if (--pre[post[idx][i]] == 0)
			{
				Q.push(post[idx][i]);
			}
		}
	}

	cout << mincost << "\n";

	return 0;
}