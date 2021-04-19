#include <iostream>
#include <string>
#include <vector>
#include <map>

#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)

using namespace std;

int same_cnt = 0;
int sum_cnt = 0;

map<string, int> info_one;
map<string, int> info_two;
map<string, int> info_visited;

vector<string> idx_vec1;
vector<string> idx_vec2;

char apb1;
char apb2;

void func_one(vector<string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		string s = vec[i];

		if (info_one[s] == 0)
		{
			idx_vec1.push_back(s);
		}

		info_one[s]++;
	}
}

void func_two(vector<string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		string s = vec[i];

		if (info_two[s] == 0)
		{
			idx_vec2.push_back(s);
		}

		info_two[s]++;
	}

	if (idx_vec1.size() < idx_vec2.size()) // 교집합 개수
	{
		for (int i = 0; i < idx_vec1.size(); i++)
		{
			if (info_two[idx_vec1[i]] != 0)
			{
				same_cnt += Min(info_one[idx_vec1[i]], info_two[idx_vec1[i]]);
			}
		}
	}
	else
	{
		for (int i = 0; i < idx_vec2.size(); i++)
		{
			if (info_one[idx_vec2[i]] != 0)
			{
				same_cnt += Min(info_one[idx_vec2[i]], info_two[idx_vec2[i]]);
			}
		}
	}

	for (int i = 0; i < idx_vec1.size(); i++) // 합집합 개수
	{
		if (info_visited[idx_vec1[i]] == 0)
		{
			info_visited[idx_vec1[i]]++;

			if (info_two[idx_vec1[i]] != 0)
			{
				sum_cnt += Max(info_one[idx_vec1[i]], info_two[idx_vec1[i]]);
			}
			else sum_cnt += info_one[idx_vec1[i]];
		}
	}

	for (int i = 0; i < idx_vec2.size(); i++)
	{
		if (info_visited[idx_vec2[i]] == 0)
		{
			info_visited[idx_vec2[i]]++;

			sum_cnt += info_two[idx_vec2[i]];
		}
	}
}

bool check_valid(int temp)
{
	if (temp >= 97 && temp <= 122)
	{
		return true;
	}
	else if (temp >= 65 && temp <= 90)
	{
		return true;
	}
	else return false;
}

char exec(int temp)
{
	char result;

	if (temp >= 97 && temp <= 122)
	{
		temp -= 32;
	}

	result = (char)temp;

	return result;
}

int solution(string str1, string str2) {
	int answer = 0;

	vector<string> s1_vec;
	vector<string> s2_vec;

	for (int i = 0; i < str1.length() - 1; i++)
	{
		int temp1 = (int)str1[i];
		int temp2 = (int)str1[i + 1];

		if (check_valid(temp1) && check_valid(temp2))
		{
			string s = "";

			apb1 = exec(temp1);
			apb2 = exec(temp2);

			s += apb1;
			s += apb2;

			s1_vec.push_back(s);
		}
	}

	for (int i = 0; i < str2.length() - 1; i++)
	{
		int temp1 = (int)str2[i];
		int temp2 = (int)str2[i + 1];

		if (check_valid(temp1) && check_valid(temp2))
		{
			string s = "";

			apb1 = exec(temp1);
			apb2 = exec(temp2);

			s += apb1;
			s += apb2;

			s2_vec.push_back(s);
		}
	}

	func_one(s1_vec);
	func_two(s2_vec);

	if (same_cnt == 0 && sum_cnt == 0)
	{
		answer = 65536;
	}
	else
	{
		double cal = (double)same_cnt / (double)sum_cnt;

		cal *= (double)65536;

		answer = (int)cal;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str1 = "aa1+aa2";
	string str2 = "AAAA12";

	int answer = solution(str1, str2);

	cout << answer << "\n";

	return 0;
}