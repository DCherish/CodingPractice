#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;
int a, b;
int cnt;

queue<int> Q;

vector<int> vec[1001];
bool visited[1001];

vector<int> answer;

void init()
{
	cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		vec[i].clear();
		visited[i] = false;
	}
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == true) continue;

		visited[i] = true;
		Q.push(i);

		while (!Q.empty())
		{
			int temp = Q.front();
			Q.pop();

			for (int j = 0; j < vec[temp].size(); j++)
			{
				if (visited[vec[temp][j]] == true) continue;

				visited[vec[temp][j]] = true;
				cnt++;

				Q.push(vec[temp][j]);
			}
		}
	}

	answer.push_back(cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;

		init();

		for (int j = 0; j < M; j++)
		{
			cin >> a >> b;

			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		solve();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}