#include <iostream>

using namespace std;

int N;

int arr[1000000];

int maxvalue = -9999999;
int minvalue = 9999999;

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

	for (int i = 0; i < N; i++)
	{
		if (arr[i] < minvalue)
		{
			minvalue = arr[i];
		}

		if (arr[i] > maxvalue)
		{
			maxvalue = arr[i];
		}
	}

	cout << minvalue << " " << maxvalue << "\n";

	return 0;
}