#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int arr[100000][3];
int mindp[2][3];
int maxdp[2][3];

int N, a, b, c, p_idx, c_idx, r_idx;
int mintemp, maxtemp;

int minans = INT_MAX;
int maxans = INT_MIN;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;

		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;
	}

	maxdp[0][0] = mindp[0][0] = arr[0][0];
	maxdp[0][1] = mindp[0][1] = arr[0][1];
	maxdp[0][2] = mindp[0][2] = arr[0][2];

	for (int i = 1; i < N; i++)
	{
		if (i % 2 == 1)
		{
			p_idx = 0;
			c_idx = 1;
		}
		else
		{
			p_idx = 1;
			c_idx = 0;
		}

		mindp[c_idx][0] = min(mindp[p_idx][0], mindp[p_idx][1]) + arr[i][0];
		maxdp[c_idx][0] = max(maxdp[p_idx][0], maxdp[p_idx][1]) + arr[i][0];

		mintemp = min(mindp[p_idx][0], mindp[p_idx][1]);
		mintemp = min(mintemp, mindp[p_idx][2]);

		maxtemp = max(maxdp[p_idx][0], maxdp[p_idx][1]);
		maxtemp = max(maxtemp, maxdp[p_idx][2]);

		mindp[c_idx][1] = mintemp + arr[i][1];
		maxdp[c_idx][1] = maxtemp + arr[i][1];

		mindp[c_idx][2] = min(mindp[p_idx][1], mindp[p_idx][2]) + arr[i][2];
		maxdp[c_idx][2] = max(maxdp[p_idx][1], maxdp[p_idx][2]) + arr[i][2];
	}

	if (N % 2 == 0)
	{
		r_idx = 1;
	}
	else r_idx = 0;

	for (int i = 0; i < 3; i++)
	{
		minans = min(minans, mindp[r_idx][i]);
		maxans = max(maxans, maxdp[r_idx][i]);
	}

	cout << maxans << " " << minans << "\n";

	return 0;
}