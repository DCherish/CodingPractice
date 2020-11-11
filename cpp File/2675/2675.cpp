#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
vector<char> answer[1000];

int T;
int times;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> times;

		cin.ignore();
		getline(cin, s);
		// 보통 정수 이후 문자를 입력할 때 cin.ignore()로 입력 버퍼의 내용을 제거한다.

		// cin.ignore(a, '\n')
		// a개의 문자를 한번에 받아들임
		// 그 후'\n'라는 문자가 나오면 그거까지만 인정하며, 그 후는 비움

		for (int j = 0; j < s.length(); j++)
		{
			for (int k = 0; k < times; k++)
			{
				answer[i].push_back(s[j]);
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
		{
			cout << answer[i][j];
		}
		cout << "\n";
	}

	return 0;
}