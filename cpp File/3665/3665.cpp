#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int T, n, m;
int a, b;

int state;
int arr[500];
int pre[500];
int rnk[500];
vector<string> answer[100];

void init()
{
	for (int i = 0; i < 500; i++)
	{
		arr[i] = 0;
		pre[i] = 0;
		rnk[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		init();
		vector<int> post[500];
		queue<int> Q;
		vector<int> temp;

		state = 1;

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];

			arr[j] -= 1;

			rnk[arr[j]] = j + 1;
		}

		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				pre[arr[k]]++;
				post[arr[j]].push_back(arr[k]);
			}
		}

		cin >> m;

		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;

			if (rnk[a - 1] < rnk[b - 1])
			{
				pre[b - 1]--;
				pre[a - 1]++;

				for (int k = 0; k < post[a - 1].size(); k++)
				{
					if (post[a - 1][k] == b - 1)
					{
						post[a - 1][k] = -7;
						break;
					}
				}

				post[b - 1].push_back(a - 1);
			}
			else
			{
				pre[b - 1]++;
				pre[a - 1]--;

				for (int k = 0; k < post[b - 1].size(); k++)
				{
					if (post[b - 1][k] == a - 1)
					{
						post[b - 1][k] = -7;
						break;
					}
				}

				post[a - 1].push_back(b - 1);
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (pre[j] == 0)
			{
				Q.push(j);
			}
		}

		while (!Q.empty())
		{
			if (Q.size() > 1)
			{
				state = 2;
				break;
			}

			int idx = Q.front();
			Q.pop();

			temp.push_back(idx + 1);

			for (int j = 0; j < post[idx].size(); j++)
			{
				if (post[idx][j] == -7) continue;

				if (--pre[post[idx][j]] == 0)
				{
					Q.push(post[idx][j]);
				}
			}
		}

		if (state == 1)
		{
			for (int j = 0; j < n; j++)
			{
				if (pre[j] != 0)
				{
					state = 3;
					break;
				}
			}

			if (state == 3)
			{
				answer[i].push_back("IMPOSSIBLE");
			}
			else
			{
				for (int j = 0; j < temp.size(); j++)
				{
					answer[i].push_back(to_string(temp[j]));
				}
			}
		}
		else if (state == 2)
		{
			for (int j = 0; j < n; j++)
			{
				if (pre[j] != 0)
				{
					state = 3;
					break;
				}
			}

			if (state == 3)
			{
				answer[i].push_back("IMPOSSIBLE");
			}
			else
			{
				answer[i].push_back("?");
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}