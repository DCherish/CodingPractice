#include <iostream>
#include <vector>

using namespace std;

int N, cmp, num;
vector<int> arr;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> cmp;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		arr.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] < cmp)
		{
			answer.push_back(arr[i]);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";

	return 0;
}