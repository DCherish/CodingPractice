#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;
int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i-1] + 1;

		if (i % 2 == 0)
		{
			arr[i] = min(arr[i], arr[i/2] + 1);
		}

		if (i % 3 == 0)
		{
			arr[i] = min(arr[i], arr[i/3] + 1);
		}
	}

	cout << arr[N] << "\n";

	return 0;
}