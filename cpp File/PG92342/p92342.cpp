#include <string>
#include <vector>

using namespace std;

vector<int> score(11);
vector<int> r_info(11);
vector<int> a_info;

int maxcost = 0;

void solve(int depth, int idx)
{
    if (depth == 0)
    {
        int r_score = 0;
        int a_score = 0;
        
        for (int i = 0; i <= 10; i++)
        {
            if (a_info[i] == 0 && r_info[i] == 0) continue;
            
            if (a_info[i] < r_info[i])
            {
                r_score += (10 - i);
            }
            else
            {
                a_score += (10 - i);
            }
        }
        
        if (a_score >= r_score) return;
        
        if (r_score - a_score > maxcost)
        {
            maxcost = r_score - a_score;
            
            score = r_info;
        }
        else if (r_score - a_score == maxcost)
        {
            for (int i = 10; i >= 0; i--)
            {
                if (score[i] == r_info[i]) continue;
                else if (score[i] < r_info[i]) break;
                else return;
            }
            
            score = r_info;
        }
        
        return;
    }
    
    for (int i = idx; i <= 10; i++)
    {
        r_info[i]++;
        solve(depth - 1, i);
        r_info[i]--;
    }
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    
    a_info = info;
    
    solve(n, 0);
    
    if (maxcost == 0) answer.push_back(-1);
    else
    {
        for (int i = 0; i < score.size(); i++)
        {
            answer.push_back(score[i]);
        }
    }
    
    return answer;
}