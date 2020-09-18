#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int M = N % 8;

	switch (M)
	{
	case 1:
		cout << "1\n";
		break;
	case 2:
		cout << "2\n";
		break;
	case 3:
		cout << "3\n";
		break;
	case 4:
		cout << "4\n";
		break;
	case 5:
		cout << "5\n";
		break;
	case 6:
		cout << "4\n";
		break;
	case 7:
		cout << "3\n";
		break;
	case 0:
		cout << "2\n";
		break;
	}
}