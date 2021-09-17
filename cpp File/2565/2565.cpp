#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int left;
	int right;
};

int N, A, B;
vector<info> vec;
int arr[100];
int dp[100];
int maxcnt = 0;
int temp, dtemp;

bool cmp(info i1, info i2)
{
	return i1.left < i2.left;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;

		vec.push_back({ A, B });
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		arr[i] = vec[i].right;
	}

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		temp = 1;
		dtemp = 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = dp[j] + 1;
			}

			if (temp > dtemp)
			{
				dtemp = temp;
			}
		}

		dp[i] = dtemp;

		if (dp[i] > maxcnt)
		{
			maxcnt = dp[i];
		}
	}

	cout << N - maxcnt << "\n";

	return 0;
}