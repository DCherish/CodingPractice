#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

class cmp
{
public:
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		else return abs(a) > abs(b);
	}
};

int N, x;

priority_queue<int, vector<int>, cmp> PQ;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x == 0)
		{
			if (PQ.empty())
			{
				answer.push_back(0);
			}
			else
			{
				answer.push_back(PQ.top());
				PQ.pop();
			}
		}
		else
		{
			PQ.push(x);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}