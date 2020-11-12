#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string s;
string temp;
vector<string> vec;

bool cmp(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		return s1 < s2;
	}
	else
	{
		return s1.length() < s2.length();
	}
}

// vector string sort

// 추가 Tip
// char 배열일 경우 문자열 비교 ; strcmp(s1, s2)
// string 끼리의 비교 ; s1.compare(s2)

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, s);

		vec.push_back(s);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].compare(temp) != 0)
		{
			cout << vec[i] << "\n";
			temp = vec[i];
		}
		else continue;
	}

	return 0;
}