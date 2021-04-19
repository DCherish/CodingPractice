#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct info
{
	int ex;
	string uid;
};

vector<info> V;

map<string, string> info_id;

void func(vector<string> vec)
{
	if (vec[0] == "Enter")
	{
		info_id[vec[1]] = vec[2];

		V.push_back({ 0, vec[1] });
	}
	else if (vec[0] == "Leave")
	{
		V.push_back({ 1, vec[1] });
	}
	else
	{
		info_id[vec[1]] = vec[2];
	}
}

vector<string> solution(vector<string> record)
{
	vector<string> answer;

	vector<string> vec;

	for (int i = 0; i < record.size(); i++)
	{
		stringstream ss(record[i]);
		string token;

		while (getline(ss, token, ' '))
		{
			vec.push_back(token);
		}

		func(vec);

		vec.clear();
	}

	for (int i = 0; i < V.size(); i++)
	{
		string str = "";

		if (V[i].ex == 0)
		{
			str = info_id[V[i].uid];
			str += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";

			answer.push_back(str);
		}
		else if (V[i].ex == 1)
		{
			str = info_id[V[i].uid];
			str += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";

			answer.push_back(str);
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> record;

	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	vector<string> answer = solution(record);

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}