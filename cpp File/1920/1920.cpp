#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int num, idx;
vector<int> vec;
vector<int> answer;

void BinarySearch(int D)
{
	int start = 0;
	int end = vec.size() - 1;
	int mid = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (vec[mid] == D)
		{
			answer.push_back(1);
			return;
		}
		else if (vec[mid] > D)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	answer.push_back(0);
	return;
}

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end(), cmp);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> idx;

		BinarySearch(idx);

		// cout << "print\n";
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}