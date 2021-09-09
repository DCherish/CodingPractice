#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct info
{
	int idx;
	int basic;
	vector<string> out_line;
	double link;
	double match;
};

map<string, int> MAP;

vector<info> page;

bool cmp(info a, info b)
{
	if (a.match == b.match)
	{
		return a.idx < b.idx;
	}
	else return a.match > b.match;
}

string make_small(string s)
{
	string temp = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] -= 'A';
			s[i] += 'a';
		}

		temp += s[i];
	}

	return temp;
}

string cnvert(string s)
{
	string target = "https://";
	int idx = s.find(target);
	idx += target.length();

	s = s.substr(idx);

	s = s.substr(0, s.find("\""));

	return s;
}

string find_url(string s)
{
	string target = "<meta property=\"og:url\" content=";

	s = s.substr(s.find(target));

	string title = cnvert(s);

	return title;
}

int find_word(string word, string s)
{
	string target1 = "<body>";
	string target2 = "</body>";

	int idx1 = s.find(target1);
	idx1 += target1.length();

	int idx2 = s.find(target2);

	s = s.substr(idx1, idx2 - idx1);

	string temp = "";
	int cnt = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			temp += s[i];
		}
		else
		{
			if (temp == word) cnt++;
			temp = "";
		}
	}

	return cnt;
}

vector<string> find_out(string s)
{
	vector<string> result;

	string target = "<a";

	while (s.find(target) != string::npos)
	{
		s = s.substr(s.find(target));
		string temp = cnvert(s);
		result.push_back(temp);

		string target2 = "</a>";
		s = s.substr(s.find(target2));
	}

	return result;
}

void cal_point()
{
	for (int i = 0; i < page.size(); i++)
	{
		vector<string> vec = page[i].out_line;
		int sz = vec.size();

		for (int j = 0; j < vec.size(); j++)
		{
			string str = vec[j];
			if (MAP[str] == 0) continue;
			int idx = MAP[str] - 1;
			page[idx].link += ((double)page[i].basic / (double)sz);
		}
	}

	for (int i = 0; i < page.size(); i++)
	{
		page[i].match = (double)page[i].basic + (double)page[i].link;
	}
}

void solve(string word, vector<string> pages)
{
	for (int i = 0; i < pages.size(); i++)
	{
		string str = make_small(pages[i]);
		string url = find_url(str);
		MAP[url] = i + 1;
		int cnt = find_word(word, str);
		vector<string> out = find_out(str);
		page.push_back({ i, cnt, out, 0.0, 0.0 });
	}

	cal_point();

	sort(page.begin(), page.end(), cmp);
}

int solution(string word, vector<string> pages)
{
	int answer = 0;

	word = make_small(word);

	solve(word, pages);

	answer = page[0].idx;

	return answer;
}