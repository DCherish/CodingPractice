#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, num, ans;
vector<int> vec;

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

	do
	{
		int sum = 0;

		for (int i = 0; i < N - 1; i++)
		{
			sum += abs(vec[i] - vec[i + 1]);
		}

		ans = max(ans, sum);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << ans << "\n";

	return 0;
}