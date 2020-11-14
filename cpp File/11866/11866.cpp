#include <iostream>
#include <queue>
#include <vector>

using namespace std;
queue<int> Q;

int N, K;
int cnt = 0;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		Q.push(i);
	}

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();
		cnt++;

		if (cnt % K == 0)
		{
			answer.push_back(idx);
		}
		else
		{
			Q.push(idx);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		if (i == 0)
		{
			cout << "<";
		}

		cout << answer[i];

		if (i == answer.size() - 1)
		{
			cout << ">\n";
		}
		else
		{
			cout << ", ";
		}
	}

	return 0;
}