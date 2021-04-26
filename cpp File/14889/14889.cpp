#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;
int arr[21][21];
vector<int> vec;

int start_sum, link_sum;
int start_first, start_second;
int link_first, link_second;
int result = INT_MAX;

int abs(int temp)
{
	if (temp < 0) temp = temp * (-1);
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N / 2; i++)
	{
		vec.push_back(0);
	}

	for (int i = 0; i < N / 2; i++)
	{
		vec.push_back(1);
	}

	do
	{
		vector<int> start;
		vector<int> link;

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] == 0) start.push_back(i + 1);
			else link.push_back(i + 1);
		}

		start_sum = 0;
		link_sum = 0;

		for (int i = 0; i < N / 2; i++)
		{
			for (int j = i + 1; j < N / 2; j++)
			{
				start_first = start[i];
				start_second = start[j];

				start_sum += arr[start_first][start_second] + arr[start_second][start_first];

				link_first = link[i];
				link_second = link[j];

				link_sum += arr[link_first][link_second] + arr[link_second][link_first];
			}
		}

		result = min(result, abs(start_sum - link_sum));

	} while (next_permutation(vec.begin(), vec.end()));

	cout << result << "\n";

	return 0;
}