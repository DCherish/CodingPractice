#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> r_info(11);
vector<int> a_info(11);

vector<int> answer;

int maxcost = 0;

void solve(int depth, int idx)
{
    if (depth == 0)
    {
        int r_score = 0;
        int a_score = 0;
        
        for (int i = 0; i < 11; i++)
        {
            if (r_info[i] == 0 && a_info[i] == 0) continue;
            
            if (r_info[i] > a_info[i]) r_score += (10 - i);
            else a_score += (10 - i);
        }
        
        if (a_score >= r_score) return;
        
        if (r_score - a_score > maxcost)
        {
            maxcost = r_score - a_score;
            
            answer.clear();
            
            for (int i = 0; i < 11; i++)
            {
                answer.push_back(r_info[i]);
            }
        }
        else if (r_score - a_score == maxcost)
        {
            for (int i = 10; i >= 0; i--)
            {
                if (answer[i] > r_info[i]) return;
                else if (answer[i] < r_info[i]) break;
                else continue;
            }
            
            answer.clear();
            
            for (int i = 0; i < 11; i++)
            {
                answer.push_back(r_info[i]);
            }
        }
        
        return;
    }
    
    for (int i = idx; i < 11; i++)
    {
        r_info[i] += 1;
        solve(depth - 1, i);
        r_info[i] -= 1;
    }
}

vector<int> solution(int n, vector<int> info)
{
    answer.push_back(-1);
    
    a_info = info;
    
    solve(n, 0);
    
    return answer;
}