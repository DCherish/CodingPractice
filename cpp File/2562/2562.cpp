#include <iostream>

using namespace std;

int arr[10];

int maxvalue = -1;
int maxindex = -1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i] > maxvalue)
		{
			maxvalue = arr[i];
			maxindex = i + 1;
		}
	}

	cout << maxvalue << "\n";
	cout << maxindex << "\n";

	return 0;
}