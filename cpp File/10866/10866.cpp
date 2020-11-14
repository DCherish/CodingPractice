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

		if (s.compare(0, 10, "push_front") == 0)
		{
			DQ.push_front(s.substr(11));
		}
		else if (s.compare(0, 9, "push_back") == 0)
		{
			DQ.push_back(s.substr(10));
		}
		else if (s.compare(0, 9, "pop_front") == 0)
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
		else if (s.compare(0, 8, "pop_back") == 0)
		{
			if (DQ.empty())
			{
				answer.push_back("-1");
			}
			else
			{
				answer.push_back(DQ.back());
				DQ.pop_back();
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