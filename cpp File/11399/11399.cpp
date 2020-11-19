#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, p, sum;

vector<int> time;

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
		cin >> p;
		time.push_back(p);
	}

	sort(time.begin(), time.end(), cmp);

	sum = time[0];

	for (int i = 1; i < time.size(); i++)
	{
		time[i] = time[i - 1] + time[i];

		sum = sum + time[i];
	}

	cout << sum << "\n";

	return 0;
}