#include <iostream>
#include <vector>
#include <queue>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int N, M;
int A, B;

int pre[32000];
vector<int> post[32000];
queue<int> Q;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		pre[B - 1]++;
		post[A - 1].push_back(B - 1);
	}

	for (int i = 0; i < N; i++)
	{
		if (pre[i] == 0)
		{
			Q.push(i);
		}
	}

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		answer.push_back(idx);

		for (int i = 0; i < post[idx].size(); i++)
		{
			if (--pre[post[idx][i]] == 0)
			{
				Q.push(post[idx][i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] + 1 << " ";
	}

	cout << "\n";

	return 0;
}