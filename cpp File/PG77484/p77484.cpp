#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> uset;

int sameCount = 0;
int zeroCount = 0;

int minRank, maxRank = 0;

int Rank[7] = { 6, 6, 5, 4, 3, 2, 1 };

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    
    for (int i = 0; i < win_nums.size(); i++)
    {
        uset.insert(win_nums[i]);
    }
    
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            zeroCount++;
        }
        else if (uset.count(lottos[i]) != 0)
        {
            sameCount++;
        }
    }
    
    minRank = Rank[sameCount];
    maxRank = Rank[sameCount + zeroCount];
    
    answer.push_back(maxRank);
    answer.push_back(minRank);
    
    return answer;
}