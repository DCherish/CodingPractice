#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> func(string p)
{
	int p_len = p.length();
	int j = 0;

	vector<int> f_vec(p_len, 0);

	for (int i = 1; i < p_len; i++)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = f_vec[j - 1];
		}

		if (p[i] == p[j])
		{
			f_vec[i] = ++j;
		}
	}

	return f_vec;
}

int KMP(string s, string p)
{
	vector<int> f_vec = func(p);

	int j = 0;

    for (int i = 0; i < s.length(); i++)
	{
		while (j > 0 && s[i] != p[j])
		{
			j = f_vec[j - 1];
		}

		if (s[i] == p[j])
		{
			if (j == p.length() - 1) return 1;
			else j += 1;
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, p;

	getline(cin, s);
	getline(cin, p);

	cout << KMP(s, p) << "\n";

	return 0;
}