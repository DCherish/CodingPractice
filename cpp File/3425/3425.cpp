#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#define MAXVALUE 1000000000

using namespace std;

vector<string> cmd;
vector<string> answer;

void solve(int idx)
{
	deque<long long> DQ;

	DQ.push_back(idx);

	bool state = false;

	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i] == "POP")
		{
			if (DQ.empty() == true)
			{
				answer.push_back("ERROR");
				state = true;
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
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
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
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.push_front(d_front);
			}
		}
		else if (cmd[i] == "SWP")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.pop_front();

				long long d_next = DQ.front();
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
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.pop_front();

				long long d_next = DQ.front();
				DQ.pop_front();

				long long d_add = d_front + d_next;

				if (d_add > MAXVALUE)
				{
					answer.push_back("ERROR");
					state = true;
					break;
				}
				else DQ.push_front(d_add);
			}
		}
		else if (cmd[i] == "SUB")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.pop_front();

				long long d_next = DQ.front();
				DQ.pop_front();

				long long d_sub = d_next - d_front;

				if (abs(d_sub) > MAXVALUE)
				{
					answer.push_back("ERROR");
					state = true;
					break;
				}
				else DQ.push_front(d_sub);
			}
		}
		else if (cmd[i] == "MUL")
		{
			if (DQ.size() <= 1)
			{
				answer.push_back("ERROR");
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.pop_front();

				long long d_next = DQ.front();
				DQ.pop_front();

				long long d_mul = d_front * d_next;

				if (abs(d_mul) > MAXVALUE)
				{
					answer.push_back("ERROR");
					state = true;
					break;
				}
				else DQ.push_front(d_mul);
			}
		}
		else if (cmd[i] == "DIV")
		{
			if (DQ.size() <= 1 || DQ.front() == 0)
			{
				answer.push_back("ERROR");
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.pop_front();

				long long d_next = DQ.front();
				DQ.pop_front();

				int cnt = 0;

				if (d_front < 0) cnt++;
				if (d_next < 0) cnt++;

				d_front = abs(d_front);
				d_next = abs(d_next);

				long long d_div = d_next / d_front;

				if (cnt == 1) d_div *= -1;

				DQ.push_front(d_div);
			}
		}
		else if (cmd[i] == "MOD")
		{
			if (DQ.size() <= 1 || DQ.front() == 0)
			{
				answer.push_back("ERROR");
				state = true;
				break;
			}
			else
			{
				long long d_front = DQ.front();
				DQ.pop_front();

				long long d_next = DQ.front();
				DQ.pop_front();

				bool op_state = true;

				if (d_next < 0) op_state = false;

				d_front = abs(d_front);
				d_next = abs(d_next);

				long long d_mod = d_next % d_front;

				if (op_state == false) d_mod *= -1;

				DQ.push_front(d_mod);
			}
		}
		else
		{
			DQ.push_front(stoll(cmd[i]));
		}
	}

	if (state == true) return;

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

			answer.push_back("");

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