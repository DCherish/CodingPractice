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

	cout << fixed; // �Ҽ� �ڸ��� ����
	cout.precision(10); // �Ҽ� �ڸ��� ����
	// fixed ���ٸ� �������� ���� ����

	cout << C << "\n";

	return 0;
}