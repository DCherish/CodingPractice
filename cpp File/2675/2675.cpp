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
		// ���� ���� ���� ���ڸ� �Է��� �� cin.ignore()�� �Է� ������ ������ �����Ѵ�.

		// cin.ignore(a, '\n')
		// a���� ���ڸ� �ѹ��� �޾Ƶ���
		// �� ��'\n'��� ���ڰ� ������ �װű����� �����ϸ�, �� �Ĵ� ���

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