#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> vec;

void cal(vector<int> temp)
{
	int time = 0;

	time += temp[0] * 60;

	time += temp[1];

	vec.push_back(time);
}

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";

	int min_time = 540;

	for (int i = 0; i < timetable.size(); i++) // ºÐ °è»ê
	{
		vector<int> temp;

		stringstream ss(timetable[i]);
		string token;

		while (getline(ss, token, ':'))
		{
			temp.push_back(stoi(token));
		}

		cal(temp);
	}

	sort(vec.begin(), vec.end());

	int idx = 0;
	int f_time = 0;

	for (int i = 0; i < n; i++)
	{
		int full = m;

		for (int j = idx; j < vec.size(); j++)
		{
			if (vec[j] <= min_time)
			{
				idx++;
				full--;

				if (full == 0) break;
			}
		}

		if (i + 1 == n)
		{
			if (full == 0)
			{
				f_time = vec[idx - 1] - 1;
			}
			else
			{
				f_time = min_time;
			}
		}

		min_time += t;
	}

	int hr = f_time / 60;
	int mt = f_time % 60;

	if (hr < 10)
	{
		answer += "0" + to_string(hr);
	}
	else
	{
		answer += to_string(hr);
	}

	answer += ":";

	if (mt < 10)
	{
		answer += "0" + to_string(mt);
	}
	else
	{
		answer += to_string(mt);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t, m;
	vector<string> timetable;

	cin >> n >> t >> m;

	timetable.push_back("09:10");
	timetable.push_back("09:09");
	timetable.push_back("08:00");

	string str = solution(n, t, m, timetable);

	cout << str << "\n";

	return 0;
}