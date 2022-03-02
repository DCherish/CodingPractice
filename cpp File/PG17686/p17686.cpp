#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cvt
{
	string head;
	int number;
};

struct info
{
	cvt c;
	int idx;
};

bool cmp(info a, info b)
{
	if (a.c.head == b.c.head)
	{
		if (a.c.number == b.c.number)
		{
			return a.idx < b.idx;
		}
		else return a.c.number < b.c.number;
	}
	else return a.c.head < b.c.head;
}

cvt cnvert(string s)
{
	cvt result;

	result.head = "";
	result.number = 0;

	int temp;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			result.head += s[i];
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			result.head += tolower(s[i]);
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			temp = i;
			break;
		}
		else result.head += s[i];
	}

	for (int i = temp; i < temp + 5; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result.number *= 10;
			result.number += (int)(s[i] - '0');
		}
		else break;
	}

	return result;
}

vector<string> solution(vector<string> files)
{
	vector<string> answer;

	vector<info> vec;

	for (int i = 0; i < files.size(); i++)
	{
		cvt cv = cnvert(files[i]);
		vec.push_back({ cv, i });
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		answer.push_back(files[vec[i].idx]);
	}

	return answer;
}