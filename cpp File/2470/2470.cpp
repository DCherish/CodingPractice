#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, num;
vector<int> vec;

int idx1, idx2;

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

	sort(vec.begin(), vec.end(), less<int>());

	int start = 0;
	int end = N - 1;

	int min_sum = INT_MAX;

	while (start < end)
	{
		int sum = vec[start] + vec[end];

		if (sum == 0)
		{
			idx1 = start;
			idx2 = end;

			break;
		}

		if (abs(sum) < min_sum)
		{
			min_sum = abs(sum);

			idx1 = start;
			idx2 = end;
		}

		if (sum < 0) start++;
		else end--;
	}

	cout << vec[idx1] << " " << vec[idx2] << "\n";

	return 0;
}