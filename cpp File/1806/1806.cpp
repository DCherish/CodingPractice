#include <iostream>
#include <algorithm>

using namespace std;

int N, S, ans;
int arr[100000];
int p_sum[100001];

void t_pointer()
{
	int start = 0;
	int end = 0;

	while (start < N && end < N)
	{
		int sum = 0;

		for (int i = start; i <= end; i++)
		{
			sum += arr[i];
		}

		if (sum >= S)
		{
			int temp = end - start + 1;

			if (ans == 0)
			{
				ans = temp;
			}
			else
			{
				ans = min(temp, ans);
			}
		}

		if (sum <= S) end++;
		else start++;
	}
}

void p_sum_t_pointer()
{
	for (int i = 1; i <= N; i++)
	{
		p_sum[i] = p_sum[i - 1] + arr[i - 1];
	}

	int start = 1;
	int end = 1;

	while (start <= N && end <= N)
	{
		int sum = p_sum[end] - p_sum[start - 1];

		if (sum >= S)
		{
			int temp = end - start + 1;

			if (ans == 0)
			{
				ans = temp;
			}
			else
			{
				ans = min(temp, ans);
			}
		}

		if (sum <= S) end++;
		else start++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//t_pointer();
	p_sum_t_pointer();

	cout << ans << "\n";

	return 0;
}