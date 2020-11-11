#include <iostream>
#include <vector>
#include <queue>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int N;

int t[500];
int cnt[500];
int result[500];
vector<int> post[500];
queue<int> Q;

int num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> t[i];

		cin >> num;

		if (num != -1)
		{
			post[num - 1].push_back(i);
			cnt[i]++;

			cin >> num;

			while (num != -1)
			{
				post[num - 1].push_back(i);
				cnt[i]++;

				cin >> num;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		result[i] = t[i];

		if (cnt[i] == 0)
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
			result[post[idx][i]] = Max(result[post[idx][i]], t[post[idx][i]] + result[idx]);

			if (--cnt[post[idx][i]] == 0)
			{
				Q.push(post[idx][i]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}