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

	// cout << s.substr() << endl; // 문자열 전체 추출
	// cout << s.substr(7) << endl; // 8번째 원소부터 추출
	// cout << s.substr(2, 4) << endl; // 3번째 원소부터 5번째까지 추출
	// cout << s.substr(str.find('f')) << endl; // f를 찾은 부분부터 추출

	cout << cnt + 1 << "\n";

	return 0;
}