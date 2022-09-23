#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

string rvs_cnvert(int num)
{
    string result = "";
    
    if (num / 60 < 10) result += "0";
    result += to_string(num / 60);
    
    result += ":";
    
    if (num % 60 < 10) result += "0";
    result += to_string(num % 60);
    
    return result;
}

int cnvert(string s)
{
	int result = 0;

	result += stoi(s.substr(0, 2)) * 60;
	result += stoi(s.substr(3, 2));

	return result;
}

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";

	int min_time = 540;

	for (int i = 0; i < timetable.size(); i++)
	{
		int time = cnvert(timetable[i]);
        
        vec.push_back(time);
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
			else break;
		}

		if (i + 1 == n)
		{
			if (full == 0) f_time = vec[idx - 1] - 1;
			else f_time = min_time;
		}

		min_time += t;
	}

	answer = rvs_cnvert(f_time);

	return answer;
}