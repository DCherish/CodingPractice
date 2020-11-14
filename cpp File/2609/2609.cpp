#include <iostream>
#define Min(a, b) (a < b ? a : b)

using namespace std;

int A, B;
int tempa, tempb, idx;
int GCD, LCM;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	tempa = A;
	tempb = B;

	idx = Min(tempa, tempb);

	while (idx != 0)
	{
		int r = tempa % tempb;

		tempa = tempb;
		tempb = r;

		idx = r;
	}

	GCD = tempa;
	LCM = A * B / GCD;

	cout << GCD << "\n";
	cout << LCM << "\n";

	return 0;
}