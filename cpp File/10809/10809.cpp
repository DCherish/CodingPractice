#include <iostream>
#include <string>

using namespace std;

string s;
int alphabet[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, s);

	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = -1;
	}

	for (int i = 0; i < s.length(); i++)
	{
		int temp = (int)s[i] - (int)'a';

		if (alphabet[temp] == -1)
		{
			alphabet[temp] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}

	cout << "\n";

	return 0;
}