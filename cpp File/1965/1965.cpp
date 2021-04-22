#include <iostream>

using namespace std;

int n, temp, dtemp;
int arr[1001];
int darr[1001];

int maxcnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		temp = 0;
		dtemp = 0;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = darr[j] + 1;

				if (temp > dtemp)
				{
					dtemp = temp;
				}
			}
		}

		darr[i] = dtemp;

		if (darr[i] > maxcnt)
		{
			maxcnt = darr[i];
		}
	}

	cout << maxcnt << "\n";

	return 0;
}