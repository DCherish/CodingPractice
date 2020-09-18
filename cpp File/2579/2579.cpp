#include <iostream>
#include <algorithm>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int N;
int arr[301] = { 0, };
int darr[301] = { 0, };

void DP()
{
	darr[1] = arr[1];
	darr[2] = Max(arr[2], arr[1] + arr[2]);
	darr[3] = Max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= N; i++)
	{
		darr[i] = Max(darr[i - 2] + arr[i], darr[i - 3] + arr[i - 1] + arr[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	DP();

	cout << darr[N] << "\n";

	return 0;
}