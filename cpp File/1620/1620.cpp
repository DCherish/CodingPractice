#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N, M;
string s;

map<string, int> alphaint;
vector<string> intalpha;

vector<string> answer;

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

		alphaint[s] = i + 1;
		intalpha.push_back(s);
	}

	for (int i = 0; i < M; i++)
	{
		getline(cin, s);

		if (s[0] >= '0' && s[0] <= '9')
		{
			int idx = stoi(s);
			answer.push_back(intalpha[idx - 1]);
		}
		else
		{
			answer.push_back(to_string(alphaint[s]));
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}