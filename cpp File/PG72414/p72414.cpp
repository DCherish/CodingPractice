#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int cnvert(string s)
{
	int result = 0;

	string hour = s.substr(0, 2);
	string minute = s.substr(3, 2);
	string second = s.substr(6, 2);

	result += stoi(hour) * 3600;
	result += stoi(minute) * 60;
	result += stoi(second);

	return result;
}

string rvs_cnvert(int num)
{
	string result = "";

	int temp = num / 3600;

	if (temp < 10) result += "0";
	result += to_string(temp) + ":";
	num %= 3600;

	temp = num / 60;

	if (temp < 10) result += "0";
	result += to_string(temp) + ":";
	num %= 60;

	temp = num;

	if (temp < 10) result += "0";
	result += to_string(temp);

	return result;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
	string answer = "";

	int pt = cnvert(play_time);
	int at = cnvert(adv_time);

	vector<ll> timeline(pt + 1, 0);

	for (int i = 0; i < logs.size(); i++)
	{
		string front = logs[i].substr(0, 8);
		string back = logs[i].substr(9, 8);

		int ft = cnvert(front);
		int bt = cnvert(back);

		timeline[ft]++;
		timeline[bt]--;
	}

	for (int i = 1; i <= pt; i++)
	{
		timeline[i] += timeline[i - 1];
	}

	for (int i = 1; i <= pt; i++)
	{
		timeline[i] += timeline[i - 1];
	}

    // 0 - at초
	ll result = timeline[at - 1];
	int result_idx = 0;

	for (int i = at; i <= pt; i++)
	{
		if (timeline[i] - timeline[i - at] > result)
		{
			result = timeline[i] - timeline[i - at];
			result_idx = i - at + 1;
		}
	}

	answer = rvs_cnvert(result_idx);

	return answer;
}