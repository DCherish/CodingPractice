#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int cal(string s)
{
	stack<char> stk;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') stk.push(s[i]);
		else if (s[i] == ')')
		{
			if (stk.empty()) return 0;
			if (stk.top() != '(') return 0;

			stk.pop();
		}
		else if (s[i] == '}')
		{
			if (stk.empty()) return 0;
			if (stk.top() != '{') return 0;

			stk.pop();
		}
		else if (s[i] == ']')
		{
			if (stk.empty()) return 0;
			if (stk.top() != '[') return 0;

			stk.pop();
		}
	}

	return 1;
}

int solution(string s)
{
	int answer = 0;

	int sl_cnt = 0;
	int sr_cnt = 0;

	int ml_cnt = 0;
	int mr_cnt = 0;

	int bl_cnt = 0;
	int br_cnt = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') sl_cnt++;
		else if (s[i] == ')') sr_cnt++;
		else if (s[i] == '{') ml_cnt++;
		else if (s[i] == '}') mr_cnt++;
		else if (s[i] == '[') bl_cnt++;
		else if (s[i] == ']') br_cnt++;
	}

	string temp = "";

	if (sl_cnt < sr_cnt) temp = "(";
	else if (sl_cnt > sr_cnt) temp = ")";
	else if (ml_cnt < mr_cnt) temp = "{";
	else if (ml_cnt > mr_cnt) temp = "}";
	else if (bl_cnt < br_cnt) temp = "[";
	else if (bl_cnt > br_cnt) temp = "]";

	for (int i = 0; i < s.length() + 1; i++)
	{
		string str = s.substr(0, i) + temp + s.substr(i);

		answer += cal(str);
	}

	return answer;
}

int main()
{
	//기존 프로젝트를 mac과 연동 test
	//123123
	//string s = "[]([[]){}";
	//string s = "{([()]))}";
	//string s = "(()()()";
	string s = "(){{}}}";

	cout << solution(s) << "\n";

	return 0;
}