#include <iostream>
#include <map>
#include <string>

using namespace std;

int M, x;
string s;

map<int, bool> mp;

void init()
{
	for (int i = 1; i <= 20; i++)
	{
		mp[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M;
	cin.ignore();

	init();

	for (int i = 0; i < M; i++)
	{
		getline(cin, s);

		if (s.compare(0, 3, "add") == 0)
		{
			x = stoi(s.substr(4));

			if (mp[x] == false)
			{
				mp[x] = true;
			}
		}
		else if (s.compare(0, 6, "remove") == 0)
		{
			x = stoi(s.substr(7));

			if (mp[x] == true)
			{
				mp[x] = false;
			}
		}
		else if (s.compare(0, 5, "check") == 0)
		{
			x = stoi(s.substr(6));

			if (mp[x] == true)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (s.compare(0, 6, "toggle") == 0)
		{
			x = stoi(s.substr(7));

			if (mp[x] == true)
			{
				mp[x] = false;
			}
			else
			{
				mp[x] = true;
			}
		}
		else if (s.compare(0, 3, "all") == 0)
		{
			for (int i = 1; i <= 20; i++)
			{
				mp[i] = true;
			}
		}
		else if (s.compare(0, 5, "empty") == 0)
		{
			for (int i = 1; i <= 20; i++)
			{
				mp[i] = false;
			}
		}
	}

	return 0;
}