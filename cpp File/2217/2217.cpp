#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, r;
vector<int> rope;
int temp;
int maxcost = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> r;
		rope.push_back(r);
	}

	sort(rope.begin(), rope.end(), greater<int>());

	for (int i = 0; i < N; i++)
	{
		temp = rope[i] * (i + 1);

		if (temp > maxcost)
		{
			maxcost = temp;
		}
	}

	cout << maxcost << "\n";

	return 0;
}