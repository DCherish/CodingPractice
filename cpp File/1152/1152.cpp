#include <iostream>
#include <string>

using namespace std;

string s;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') cnt++;
	}

	if (s[0] == ' ')
	{
		cnt--;
	}

	if (s[s.length() - 1] == ' ')
	{
		cnt--;
	}

	// cout << s.substr() << endl; // ���ڿ� ��ü ����
	// cout << s.substr(7) << endl; // 8��° ���Һ��� ����
	// cout << s.substr(2, 4) << endl; // 3��° ���Һ��� 5��°���� ����
	// cout << s.substr(str.find('f')) << endl; // f�� ã�� �κк��� ����

	cout << cnt + 1 << "\n";

	return 0;
}