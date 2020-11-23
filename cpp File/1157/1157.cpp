#include <iostream>
#include <string>

using namespace std;

string s;
int apb[26];
int maxcnt = -1;
int maxidx = -1;
bool state = true;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		int temp = (int)s[i];

		if (temp >= 97)
		{
			temp = temp - (int)'a';
		}
		else
		{
			temp = temp - (int)'A';
		}

		apb[temp]++;

		if (apb[temp] > maxcnt)
		{
			maxcnt = apb[temp];
			maxidx = temp;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (apb[i] == maxcnt && i != maxidx)
		{
			state = false;
			break;
		}
	}

	if (state == true)
	{
		int result = maxidx + 65;

		cout << (char)result << "\n";
	}
	else
	{
		cout << "?\n";
	}

	return 0;
}