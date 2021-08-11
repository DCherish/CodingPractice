#include <iostream>

using namespace std;

int A, B, C, D;

int gcd(int x, int y)
{
	if (x < y)
	{
		int temp = x;
		int x = y;
		int y = temp;
	}

	while (true)
	{
		if (x % y == 0) return y;

		int temp = x % y;
		x = y;
		y = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;
	cin >> C >> D;

	int front = A * D + B * C;
	int back = B * D;

	int gcd_num = gcd(front, back);

	cout << front / gcd_num << " " << back / gcd_num << "\n";

	return 0;
}