#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec;

string str = "AEIOU";

void makeword(string s)
{
	if (s.length() >= 5)
	{
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		string temp = s + str[i];
		vec.push_back(temp);
		makeword(temp);
	}
}

int solution(string word)
{
	int answer = 0;

	makeword("");

	answer = lower_bound(vec.begin(), vec.end(), word) - vec.begin() + 1;

	return answer;
}