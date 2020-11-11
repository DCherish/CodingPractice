#include <iostream>

using namespace std;

int A, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	if (A > B)
	{
		cout << ">" << "\n";
	}
	else if (A < B)
	{
		cout << "<" << "\n";
	}
	else
	{
		cout << "==" << "\n";
	}

	return 0;
}