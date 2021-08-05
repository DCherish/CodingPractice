#include <iostream>

using namespace std;

long long n;

int arr[1500001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i < 1500000; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}

	n %= 1500000;

	cout << arr[n] << "\n";

	return 0;
}