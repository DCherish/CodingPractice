#include <iostream>
#include <algorithm>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int arr[10001] = { 0, };
int darr[10001] = { 0, };

int n;
int maxq = 0;

void DP()
{
	darr[1] = arr[1];
	darr[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		darr[i] = Max(darr[i - 3] + arr[i - 1] + arr[i], darr[i - 2] + arr[i]);
		darr[i] = Max(darr[i], darr[i - 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	DP();

	cout << darr[n] << "\n";

	return 0;
}