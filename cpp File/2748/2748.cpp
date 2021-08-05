#include <iostream>

using namespace std;

int n;
long long arr[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n] << "\n";

	return 0;
}