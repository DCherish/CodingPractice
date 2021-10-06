#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> H;

	vector<int> bottom(N / 2);
	vector<int> top(N / 2);

	for (int i = 0; i < N / 2; i++)
	{
		cin >> bottom[i] >> top[i];
	}

	sort(bottom.begin(), bottom.end(), less<int>());
	sort(top.begin(), top.end(), less<int>());

	int result = N;
	int cnt = 1;

	for (int i = 1; i <= H; i++)
	{
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());

		temp += top.size() - (lower_bound(top.begin(), top.end(), H - i + 1) - top.begin());

		if (result == temp) cnt++;
		else if (result > temp)
		{
			result = temp;
			cnt = 1;
		}
	}

	cout << result << " " << cnt << "\n";

	return 0;
}