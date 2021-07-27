#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int arr[100000];

priority_queue<int, vector<int>, less<int>> PQ_max;
priority_queue<int, vector<int>, greater<int>> PQ_min;

vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (PQ_max.size() > PQ_min.size()) PQ_min.push(arr[i]);
		else PQ_max.push(arr[i]);

		if (!PQ_max.empty() && !PQ_min.empty())
		{
			if (PQ_max.top() > PQ_min.top())
			{
				int max_value = PQ_max.top();
				int min_value = PQ_min.top();

				PQ_max.pop();
				PQ_min.pop();

				PQ_max.push(min_value);
				PQ_min.push(max_value);
			}
		}

		answer.push_back(PQ_max.top());
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}