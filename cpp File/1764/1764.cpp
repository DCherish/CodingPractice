#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string s;

map<string, int> info;
vector<string> answer;

bool cmp(string s1, string s2)
{
	return s1 < s2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, s);

		info[s]++;
	}

	for (int i = 0; i < M; i++)
	{
		getline(cin, s);

		if (info.count(s) != 0)
		{
			answer.push_back(s);
		}
		else continue;
	}

	sort(answer.begin(), answer.end(), cmp);

	cout << answer.size() << "\n";

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}