#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int N;
int sum = 0;
int idx = 9;

int alphabet[26];
vector<int> answer;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin.ignore(256, '\n');

	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s);

		for (int j = 0; j < s.length(); j++)
		{
			alphabet[s[j] - 65] += (int)pow(10, s.length() - j - 1);
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] != 0)
		{
			answer.push_back(alphabet[i]);
		}
	}

	sort(answer.begin(), answer.end(), cmp);

	for (int i = 0; i < answer.size(); i++)
	{
		sum += answer[i] * idx;
		idx--;
	}

	cout << sum << "\n";

	return 0;
}