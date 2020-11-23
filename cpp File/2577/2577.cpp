#include <iostream>
#include <string>

using namespace std;

int A, B, C, R;
int cnt[10];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;

	R = A * B * C;

	s = to_string(R);

	for (int i = 0; i < s.length(); i++)
	{
		int temp = (int)s[i] - (int)'0';
		cnt[temp]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << "\n";
	}

	return 0;
}