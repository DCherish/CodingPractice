#include <iostream>

using namespace std;

int arr[10];

bool isitA()
{
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] != i + 1)
		{
			return false;
		}
	}

	return true;
}

bool isitD()
{
	for (int i = 0; i < 8; i++)
	{
		if (arr[i] != 8 - i)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}

	if (isitA() == true)
	{
		cout << "ascending" << "\n";
	}
	else if (isitD() == true)
	{
		cout << "descending" << "\n";
	}
	else
	{
		cout << "mixed" << "\n";
	}

	return 0;
}