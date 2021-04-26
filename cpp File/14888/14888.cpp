#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int max_answer = INT_MIN;
int min_answer = INT_MAX;

int N, num;
int arr[12];
int op[4];

void DFS(int p, int m, int t, int d, int cnt, int sum)
{
	if (cnt == N)
	{
		max_answer = max(max_answer, sum);
		min_answer = min(min_answer, sum);
	}

	if (p > 0)
	{
		DFS(p - 1, m, t, d, cnt + 1, sum + arr[cnt]);
	}

	if (m > 0)
	{
		DFS(p, m - 1, t, d, cnt + 1, sum - arr[cnt]);
	}

	if (t > 0)
	{
		DFS(p, m, t - 1, d, cnt + 1, sum * arr[cnt]);
	}

	if (d > 0)
	{
		DFS(p, m, t, d - 1, cnt + 1, sum / arr[cnt]);
	}
}

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

	for (int i = 0; i < 4; i++)
	{
		cin >> num;

		op[i] = num;
	}

	DFS(op[0], op[1], op[2], op[3], 1, arr[0]);

	cout << max_answer << "\n";
	cout << min_answer << "\n";

	return 0;
}