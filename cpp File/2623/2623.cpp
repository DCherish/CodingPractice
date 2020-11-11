#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int num;

int arr[1000];
int cnt[1000];
bool visited[1000];
int state = 0;
vector<int> post[1000];
vector<int> answer;
queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			cin >> arr[j];
			arr[j] -= 1;
		}

		for (int j = 0; j < num - 1; j++)
		{
			cnt[arr[j + 1]]++;
			post[arr[j]].push_back(arr[j + 1]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0)
		{
			Q.push(i);
		}
	}

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		if (visited[idx] == true)
		{
			state = 1;
			break;
		}

		answer.push_back(idx + 1);
		visited[idx] = true;

		for (int i = 0; i < post[idx].size(); i++)
		{
			if (--cnt[post[idx][i]] == 0)
			{
				Q.push(post[idx][i]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (cnt[i] != 0)
		{
			state = 1;
			break;
		}
	}

	if (state == 0)
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << "\n";
		}
	}
	else
	{
		cout << "0" << "\n";
	}

	return 0;
}