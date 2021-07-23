#include <iostream>
#include <vector>

using namespace std;

int maxcnt, maxidx;

int temp, dtemp;

int N;
int arr[1000];
int dp[1000];
vector<int> vec[1000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 1;
	vec[0].push_back(arr[0]);

	maxcnt = 1;
	maxidx = 0;

	for (int i = 1; i < N; i++)
	{
		temp = 0;
		dtemp = 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = dp[j] + 1;

				if (temp > dtemp)
				{
					dtemp = temp;

					vec[i].clear();

					for (int k = 0; k < vec[j].size(); k++)
					{
						vec[i].push_back(vec[j][k]);
					}
				}
			}
		}

		dp[i] = dtemp;
		vec[i].push_back(arr[i]);

		if (dp[i] > maxcnt)
		{
			maxcnt = dp[i];
			maxidx = i;
		}
	}

	cout << maxcnt << "\n";

	for (int i = 0; i < vec[maxidx].size(); i++)
	{
		cout << vec[maxidx][i] << " ";
	}

	cout << "\n";

	return 0;
}