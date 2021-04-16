#include <iostream>
#include <string>
#include <stack>
#include <deque>

using namespace std;

deque<char> DQ_1;
deque<char> DQ_2;

stack<char> S;

int l_cnt;
int r_cnt;

string u_func();
string v_func();

string u_func()
{
	string answer = "";

	deque<char> DQ_t;

	bool state = true;

	while (!DQ_2.empty())
	{
		char front = DQ_2.front();
		DQ_2.pop_front();

		DQ_t.push_back(front); // 잘라낸 식 보관

		if (front == '(')
		{
			S.push(front);
		}
		else
		{
			if (S.empty())
			{
				while (!DQ_2.empty())
				{
					DQ_t.push_back(DQ_2.front());
					DQ_2.pop_front();
				}

				state = false;
			}
			else
			{
				S.pop();
			}
		}
	}

	if (state == false) // 거짓으로 판명난 경우
	{
		answer += "(";

		answer += v_func();

		answer += ")";

		DQ_t.pop_front();

		while (DQ_t.size() > 1)
		{
			char temp = DQ_t.front();
			DQ_t.pop_front();

			if (temp == '(')
			{
				answer += ")";
			}
			else
			{
				answer += "(";
			}
		}
	}
	else
	{
		while (!DQ_t.empty())
		{
			char temp = DQ_t.front();
			DQ_t.pop_front();

			answer += temp;
		}
	}

	return answer;
}

string v_func()
{
	string answer = "";

	l_cnt = 0;
	r_cnt = 0;

	while (!DQ_1.empty())
	{
		char front = DQ_1.front();
		DQ_1.pop_front();

		DQ_2.push_back(front); // 식에서 잘라내기

		if (front == '(')
		{
			l_cnt++;
		}
		else
		{
			r_cnt++;
		}

		if (l_cnt == r_cnt)
		{
			answer += u_func();
			answer += v_func();

			l_cnt = 0;
			r_cnt = 0;
		}
	}

	return answer;
}

string solution(string p)
{
	string answer = "";

	l_cnt = 0;
	r_cnt = 0;

	for (int i = 0; i < p.length(); i++)
	{
		DQ_1.push_back(p[i]); // 원래 식 입력
	}

	while (!DQ_1.empty())
	{
		char front = DQ_1.front();
		DQ_1.pop_front();

		DQ_2.push_back(front); // 식에서 잘라내기

		if (front == '(')
		{
			l_cnt++;
		}
		else
		{
			r_cnt++;
		}

		if (l_cnt == r_cnt)
		{
			answer += u_func();
			answer += v_func();

			l_cnt = 0;
			r_cnt = 0;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string p1 = "(()())()";
	string p2 = ")(";
	string p3 = "()))((()";
	string p4 = ")()()()(";

	cout << solution(p1) << "\n";
	cout << solution(p2) << "\n";
	cout << solution(p3) << "\n";
	cout << solution(p4) << "\n";

	return 0;
}