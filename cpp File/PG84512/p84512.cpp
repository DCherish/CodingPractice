#include <string>
#include <vector>

using namespace std;

string aeiou = "AEIOU";
string str;

int answer = 0;

bool state = true;
int cnt = 0;

void DFS(string s)
{
    if (!state) return;

	if (s.compare(str) == 0)
	{
		state = false;
		answer = cnt;

		return;
	}
    
    if (s.length() == 5) return;

	for (int i = 0; i < aeiou.length(); i++)
	{
		if(!state) return;

		cnt++;
		DFS(s + aeiou[i]);
	}
}

int solution(string word)
{  
    str = word;
    
    DFS("");
    
    return answer;
}