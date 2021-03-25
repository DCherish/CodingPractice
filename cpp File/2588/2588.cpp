#include <iostream>

using namespace std;

int A, B;
int C, D, E, F;
int one, ten;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	one = B % 100;
	one = one % 10;

	C = A * one;

	ten = B % 100;

	D = A * (ten - one);
	D /= 10;

	E = A * (B - ten);
	E /= 100;

	F = A * B;

	cout << C << "\n";
	cout << D << "\n";
	cout << E << "\n";
	cout << F << "\n";

	return 0;
}