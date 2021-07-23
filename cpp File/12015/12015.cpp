#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1000001];
vector<int> vec;

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

	vec.push_back(arr[0]);

	for (int i = 1; i < N; i++)
	{
		if (vec.back() < arr[i])
		{
			vec.push_back(arr[i]);
		}
		else
		{
			int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();

			vec[idx] = arr[i];
		}
	}

	cout << vec.size() << "\n";

	return 0;
}