#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001] = { 0, };

int n;
int maxcost;

void DP()
{
	maxcost = arr[1];

	if (arr[1] < 0)
	{
		arr[1] = 0;
	}

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i] + arr[i - 1];

		if (arr[i] > maxcost)
		{
			maxcost = arr[i];
		}

		if (arr[i] < 0)
		{
			arr[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	DP();

	cout << maxcost << "\n";

	return 0;
}