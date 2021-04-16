#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		string temp = s.substr(i, s.length());

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), less<string>());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}

	return 0;
}