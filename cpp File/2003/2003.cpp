#include <iostream>

using namespace std;

int N, M;
int arr[10001];
int p_sum[10001];

int cnt = 0;

void Two_pointer()
{
	int start = 1;
	int end = 1;

	while (start <= N && end <= N)
	{
		int sum = p_sum[end] - p_sum[start - 1];

		if (sum == M) cnt++;

		if (sum <= M) end++;
		else start++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) // prefix_sum
	{
		p_sum[i] += p_sum[i - 1] + arr[i];
	}

	Two_pointer();

	cout << cnt << "\n";

	return 0;
}