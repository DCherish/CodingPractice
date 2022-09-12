#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

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
		temp += tolower(s[i]);
	}

	return temp;
}

string cnvert(string s)
{
	string target = "https://";
	
    s = s.substr(s.find(target));

	s = s.substr(0, s.find("\""));

	return s;
}

void cal_point()
{
	for (int i = 0; i < page.size(); i++)
	{
		vector<string> vec = page[i].out_line;
		int sz = vec.size();

		for (int j = 0; j < sz; j++)
		{
			string str = vec[j];
			if (MAP.count(str) == 0) continue;
			int idx = MAP[str];
			page[idx].link += ((double)page[i].basic / (double)sz);
		}
	}

	for (int i = 0; i < page.size(); i++)
	{
		page[i].match = (double)page[i].basic + (double)page[i].link;
	}
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

int find_word(string word, string s)
{
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

string find_url(string s)
{
    string target = "<meta property=\"og:url\" content=";
    
    s = s.substr(s.find(target));

	string title = cnvert(s);

	return title;
}

void solve(string word, vector<string> pages)
{
	for (int i = 0; i < pages.size(); i++)
	{
		string str = make_small(pages[i]);
		string url = find_url(str);
		MAP[url] = i;
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