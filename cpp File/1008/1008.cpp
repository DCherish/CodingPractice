#include <iostream>

using namespace std;

int A, B;
double C;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	C = (double)A / (double)B;

	cout << fixed; // 소수 자리수 고정
	cout.precision(10); // 소수 자리수 설정
	// fixed 없다면 정수까지 개수 포함

	cout << C << "\n";

	return 0;
}