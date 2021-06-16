#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> cmd;
vector<string> answer;

void solve(int idx)
{
	deque<int> DQ;

	DQ.push_back(idx);

	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i] == "POP")
		{
			if (DQ.empty() == true)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				DQ.pop_front();
			}
		}
		else if (cmd[i] == "INV")
		{
			if (DQ.empty() == true)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				d_front *= -1;
				DQ.push_front(d_front);
			}
		}
		else if (cmd[i] == "DUP")
		{
			if (DQ.empty() == true)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.push_front(d_front);
			}
		}
		else if (cmd[i] == "SWP")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				int d_next = DQ.front();
				DQ.pop_front();

				DQ.push_front(d_front);
				DQ.push_front(d_next);
			}
		}
		else if (cmd[i] == "ADD")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				int d_next = DQ.front();
				DQ.pop_front();

				int d_add = d_front + d_next;

				DQ.push_front(d_add);
			}
		}
		else if (cmd[i] == "SUB")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				int d_next = DQ.front();
				DQ.pop_front();

				int d_sub = d_next - d_front;

				DQ.push_front(d_sub);
			}
		}
		else if (cmd[i] == "MUL")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				int d_next = DQ.front();
				DQ.pop_front();

				int d_mul = d_front * d_next;

				DQ.push_front(d_mul);
			}
		}
		else if (cmd[i] == "DIV")
		{
			if (DQ.size() <= 1 || DQ.front() == 0)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				int d_next = DQ.front();
				DQ.pop_front();

				int cnt = 0;

				if (d_front < 0) cnt++;
				if (d_next < 0) cnt++;

				d_front = abs(d_front);
				d_next = abs(d_next);

				int d_div = d_next / d_front;

				if (cnt == 1) d_div *= -1;

				DQ.push_front(d_div);
			}
		}
		else if (cmd[i] == "MOD")
		{
			if (DQ.size() <= 1 || DQ.front() == 0)
			{
				answer.push_back("ERROR");
				break;
			}
			else
			{
				int d_front = DQ.front();
				DQ.pop_front();

				int d_next = DQ.front();
				DQ.pop_front();

				d_front = abs(d_front);
				d_next = abs(d_next);

				int d_mod = d_next % d_front;

				if (d_next < 0) d_mod *= -1;

				DQ.push_front(d_mod);
			}
		}
		else
		{
			DQ.push_front(stoi(cmd[i]));
		}
	}

	if (DQ.size() != 1)
	{
		answer.push_back("ERROR");
	}
	else
	{
		string ans = to_string(DQ.front());
		answer.push_back(ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (;;)
	{
		string str;

		cin.ignore(256, '\n');
		getline(cin, str);

		if (str.compare("END") == 0)
		{
			int num;

			cin >> num;

			for (int i = 0; i < num; i++)
			{
				int idx;

				cin >> idx;

				solve(idx);
			}

			answer.push_back("\n");

			cmd.clear();
		}
		else if (str.compare("QUIT") == 0)
		{
			break;
		}
		else
		{
			stringstream ss(str);
			string token;

			while (getline(ss, token, ' '))
			{
				if (token == "NUM") continue;
				else
				{
					cmd.push_back(token);
				}
			}
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}