#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001] = { 0, };
int darr[1001] = { 0, };
int temp;
int dtemp;
int maxcnt = 0;

void DP()
{
	for (int i = 1; i <= N; i++)
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
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	DP();

	cout << maxcnt << "\n";

	return 0;
}