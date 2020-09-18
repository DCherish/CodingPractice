#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n, temp;
vector<int> answer;
int arr[12];

void init()
{
	for (int i = 1; i <= n; i++)
	{
		arr[i] = -1;
	}
}

int function(int cnt)
{
	if (cnt == n)
	{
		return 1;
	}
	else
	{
		int result = 0;

		if (cnt + 1 <= n)
		{
			if (arr[cnt + 1] == -1)
			{
				arr[cnt + 1] = function(cnt + 1);
			}
			result += arr[cnt + 1];
		}

		if (cnt + 2 <= n)
		{
			if (arr[cnt + 2] == -1)
			{
				arr[cnt + 2] = function(cnt + 2);
			}
			result += arr[cnt + 2];
		}

		if (cnt + 3 <= n)
		{
			if (arr[cnt + 3] == -1)
			{
				arr[cnt + 3] = function(cnt + 3);
			}
			result += arr[cnt + 3];
		}

		return result;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		init();

		temp = function(0);

		answer.push_back(temp);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}