#include <iostream>

using namespace std;

int A;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A;

	for (int i = 1; i <= A; i++)
	{
		if (30 % (i + 1) == 0) cout << i << "\n";
	}

	return 0;
}