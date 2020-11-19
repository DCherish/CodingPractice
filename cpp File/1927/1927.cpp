#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class cmp
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

priority_queue<int, vector<int>, cmp> PQ;
vector<int> answer;

int N, num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num == 0)
		{
			if (PQ.empty())
			{
				answer.push_back(0);
			}
			else
			{
				int temp = PQ.top();
				PQ.pop();

				answer.push_back(temp);
			}
		}
		else
		{
			PQ.push(num);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}