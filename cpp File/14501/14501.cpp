#include <iostream>
#include <algorithm>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int arr[31][3] = { 0, };
int darr[31] = { 0, };
int N, T, P;
int day;
int maxcost = 0;

void DP()
{
	for (int i = 1; i <= N; i++)
	{
		day = arr[i][1];

		arr[i][2] = arr[i][2] - darr[i];
		darr[i] = Max(darr[i], darr[i-1]);
		arr[i][2] = arr[i][2] + darr[i];

		if (i + day > N + 1) continue;
		
		if (arr[i][2] > darr[i + day])
		{
			arr[i + day][2] = arr[i + day][2] - darr[i + day];
			arr[i + day][2] = arr[i + day][2] + arr[i][2];
			darr[i + day] = arr[i][2];
			
			if (darr[i + day] > maxcost)
			{
				maxcost = darr[i + day];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T >> P;
		arr[i][1] = T;
		arr[i][2] = P;
	}

	DP();

	cout << maxcost << "\n";

	return 0;
}