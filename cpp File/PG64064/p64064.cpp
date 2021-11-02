#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int answer = 0;
int visited[10];

vector<string> uid;
vector<string> bid;

unordered_set<string> uset;

void DFS(int depth)
{
	if (depth == bid.size())
	{
		string str = "";

		for (int i = 0; i < uid.size(); i++)
		{
			if (visited[i]) str += to_string(i) + "/";
		}

		if (uset.count(str) == 0)
		{
			uset.insert(str);
			answer++;
		}

		return;
	}

	for (int i = 0; i < uid.size(); i++)
	{
		if (visited[i]) continue;

		string u_str = uid[i];
		string b_str = bid[depth];

		if (u_str.length() != b_str.length()) continue;

		bool state = true;

		for (int j = 0; j < b_str.length(); j++)
		{
			if (b_str[j] == '*') continue;
			else
			{
				if (u_str[j] != b_str[j])
				{
					state = false;
					break;
				}
			}
		}

		if (state)
		{
			visited[i] = true;
			DFS(depth + 1);
			visited[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	uid = user_id;
	bid = banned_id;

	DFS(0);

	return answer;
}