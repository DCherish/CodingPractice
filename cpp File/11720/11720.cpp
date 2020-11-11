#include <iostream>
#include <string>

using namespace std;

int N;
string s;
int sum = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin.ignore();

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		sum += (int)s[i] - (int)'0';
	}
	// 한 자리수 char -> int 변환

	cout << sum << "\n";

	return 0;
}