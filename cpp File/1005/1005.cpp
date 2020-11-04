#include <iostream>
#include <vector>
#include <queue>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int T;
int N, K;
int X, Y, W;

vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int time[1000] = {0};
		int pre[1000] = {0};
		int result[1000] = {0};

		vector<int> post[1000];
		queue<int> Q;

		cin >> N >> K;

		for (int j = 0; j < N; j++)
		{
			cin >> time[j];
		}

		for (int j = 0; j < K; j++)
		{
			cin >> X >> Y;

			post[X - 1].push_back(Y - 1);
			pre[Y - 1]++;
		}

		cin >> W;

		for (int i = 0; i < N; i++)
		{
			if (pre[i] == 0)
			{
				Q.push(i);
			}
		}

		while (pre[W - 1] > 0)
		{
			int idx = Q.front();
			Q.pop();

			for (int i = 0; i < post[idx].size(); i++)
			{
				result[post[idx][i]] = Max(result[post[idx][i]], result[idx] + time[idx]);
				
				if(--pre[post[idx][i]] == 0)
				{
					Q.push(post[idx][i]);
				}
			}
		}

		answer.push_back(result[W - 1] + time[W - 1]);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}