#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N, K;
int answer = 0;

vector<string> word;
bool alphabet[26];

int solve()
{
	bool readable;

	int cnt = 0;

	for (int i = 0; i < word.size(); i++)
	{
		readable = true;

		string str = word[i];

		for (int j = 0; j < str.length(); j++)
		{
			if (alphabet[str[j] - 'a'] == false)
			{
				readable = false;
				break;
			}
		}

		if (readable == true) cnt++;
	}

	return cnt;
}

void DFS(int idx, int depth)
{
	if (depth == K)
	{
		answer = max(answer, solve());
		return;
	}

	for (int i = idx; i < 26; i++)
	{
		if (alphabet[i] == true) continue;

		alphabet[i] = true;
		DFS(i + 1, depth + 1);
		alphabet[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	cin.ignore(256, '\n');

	if (K < 5)
	{
		answer = 0;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			string str;
			getline(cin, str);

			word.push_back(str);
		}

		alphabet['a' - 'a'] = true;
		alphabet['c' - 'a'] = true;
		alphabet['i' - 'a'] = true;
		alphabet['n' - 'a'] = true;
		alphabet['t' - 'a'] = true;

		K -= 5;

		DFS(0, 0);
	}

	cout << answer << "\n";

	return 0;
}