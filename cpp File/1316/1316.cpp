#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string s;

vector<string> vec;
int cnt = 0;
bool state;
bool apb[26];

void init()
{
	for (int i = 0; i < 26; i++)
	{
		apb[i] = false;
	}
}

void func()
{
	for (int i = 0; i < vec.size(); i++)
	{
		init();

		state = false;

		string temp = vec[i];
		char prev_temp = temp[0];
		apb[temp[0] - 'a'] = true;

		for (int j = 1; j < temp.length(); j++)
		{
			if (apb[temp[j] - 'a'] == true)
			{
				if (temp[j] != prev_temp)
				{
					state = true;
					break;
				}
			}
			else
			{
				prev_temp = temp[j];
				apb[temp[j] - 'a'] = true;
			}
		}

		if (state == false)
		{
			cnt++;
		}
	}
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
		getline(cin, s);

		vec.push_back(s);
	}

	func();

	cout << cnt << '\n';
}