#include <iostream>
#include <algorithm>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int cnt = 1;
int N;
int arr[200000] = { 0, };
int darr[200000] = { 0, };
int maxcost = 0;

void DP()
{
	darr[1] = arr[1];

	cnt = 1;

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				darr[cnt + i + k] = Max(darr[cnt + i + k], darr[cnt] + arr[cnt + i + k]);

				if (darr[cnt + i + k] > maxcost)
				{
					maxcost = darr[cnt + i + k];
				}
			}

			cnt++;
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
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[cnt];
			cnt++;
		}
	}

	DP();

	cout << maxcost << "\n";

	return 0;
}