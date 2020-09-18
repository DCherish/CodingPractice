#include <iostream>
#include <algorithm>

using namespace std;

int N;

long long arr[91] = { 0, };

void DP()
{
	arr[1] = 1;
	arr[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	DP();

	cout << arr[N] << "\n";

	return 0;
}