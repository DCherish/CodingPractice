#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Length;

bool isValid(string s)
{
	int len = s.length();
	int maxlen = len / 2;
	int startpoint = len - 1;
	int endpoint = len;

	for (int i = 1; i <= maxlen ; i++)
	{
		if (s.substr(startpoint - i, i).compare(s.substr(startpoint, endpoint)) == 0)
		{
			return false;
		}
		startpoint--;
	}
	return true;
}

void DFS(int cnt, string s)
{
	if (cnt == Length)
	{
		cout << s << "\n";
		exit(0);
	}

	for (int i = 1; i <= 3; i++)
	{
		if (isValid(s + to_string(i)) == true)
		{
			DFS(cnt+1, s + to_string(i));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> Length;

	DFS(1, "1");

	return 0;
}