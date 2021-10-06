#include <iostream>

using namespace std;

int N, M, a, b, k, idx;
int arr[100010];
int cmd[100010];

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

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> k;

		cmd[a] += k;
		cmd[b + 1] -= k;
	}

	for (int i = 1; i <= N; i++)
	{
		cmd[i] += cmd[i - 1];

		cout << arr[i] + cmd[i] << " ";
	}

	cout << "\n";

	return 0;
}