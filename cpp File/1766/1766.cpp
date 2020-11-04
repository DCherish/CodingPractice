#include <iostream>
#include <queue>
#include <vector>
#define Max(a, b) (a > b ? a : b)

using namespace std;

class l_cmp
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int N, M;
int A, B;
int pre[32000];
vector<int> post[32000];
priority_queue<int, vector<int>, l_cmp> pq;
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
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int idx = pq.top();
		pq.pop();

		answer.push_back(idx + 1);

		for (int i = 0; i < post[idx].size(); i++)
		{
			if (--pre[post[idx][i]] == 0)
			{
				pq.push(post[idx][i]);
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	
	cout << "\n";

	return 0;
}