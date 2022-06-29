#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> uset;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;

	int idx = 0;
	int turn = 0;

	string prev = "";

	for (int i = 0; i < words.size(); i++)
	{
        string word = words[i];
        
        if (word.length() == 1)
        {
            idx = (i % n) + 1;
			turn = (i / n) + 1;
			break;
        }
        
		if (prev == "")
		{
			uset.insert(word);
			prev = word;
		}
		else
		{
			if (prev[prev.length() - 1] != word[0])
			{
				idx = (i % n) + 1;
				turn = (i / n) + 1;
				break;
			}

			if (uset.count(word) != 0)
			{
				idx = (i % n) + 1;
				turn = (i / n) + 1;
				break;
			}
            
            uset.insert(word);
			prev = word;
		}
	}

	answer.push_back(idx);
	answer.push_back(turn);

	return answer;
}