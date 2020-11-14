#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int N;
string s;
deque<string> DQ;
vector<string> answer;

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

		if (s.compare(0, 4, "push") == 0)
		{
			DQ.push_back(s.substr(5));
		}
		else if (s.compare("pop") == 0)
		{
			if (DQ.empty())
			{
				answer.push_back("-1");
			}
			else
			{
				answer.push_back(DQ.front());
				DQ.pop_front();
			}
		}
		else if (s.compare("size") == 0)
		{
			answer.push_back(to_string(DQ.size()));
		}
		else if (s.compare("empty") == 0)
		{
			if (DQ.empty())
			{
				answer.push_back("1");
			}
			else
			{
				answer.push_back("0");
			}
		}
		else if (s.compare("front") == 0)
		{
			if (DQ.empty())
			{
				answer.push_back("-1");
			}
			else
			{
				answer.push_back(DQ.front());
			}
		}
		else if (s.compare("back") == 0)
		{
			if (DQ.empty())
			{
				answer.push_back("-1");
			}
			else
			{
				answer.push_back(DQ.back());
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}