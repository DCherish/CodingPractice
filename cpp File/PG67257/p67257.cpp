#include <string>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;

bool op[3];
int cnt = 0;

deque<ll> DQ;

bool visited[3];
vector<ll> opvec;

ll answer = 0;

void solve(int depth)
{
    if (depth == cnt)
    {
        deque<ll> DQ_temp = DQ;
        
        for (int i = 0; i < cnt; i++)
        {
            int idx = 1;    
            
            while (idx < DQ_temp.size())
            {
                if (DQ_temp[idx] == opvec[i])
                {
                    if (opvec[i] == 0)
                    {
                        DQ_temp[idx - 1] += DQ_temp[idx + 1];
                        DQ_temp.erase(DQ_temp.begin() + idx, DQ_temp.begin() + idx + 2);
                    }
                    else if (opvec[i] == 1)
                    {
                        DQ_temp[idx - 1] -= DQ_temp[idx + 1];
                        DQ_temp.erase(DQ_temp.begin() + idx, DQ_temp.begin() + idx + 2);
                    }
                    else if (opvec[i] == 2)
                    {
                        DQ_temp[idx - 1] *= DQ_temp[idx + 1];
                        DQ_temp.erase(DQ_temp.begin() + idx, DQ_temp.begin() + idx + 2);
                    }
                }
                else idx += 2;
            }
        }
        
        answer = max(answer, abs(DQ_temp[0]));
        
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (!op[i]) continue;
        if (visited[i]) continue;
        
        visited[i] = true;
        opvec.push_back((ll)i);
        
        solve(depth + 1);
        
        opvec.pop_back();
        visited[i] = false;
    }
}

void func(ll idx, string s)
{
    op[idx] = true;
    
    DQ.push_back(stoll(s));
    DQ.push_back(idx);
}

ll solution(string expression)
{
    int idx = 0;
    
    string str = "";
    
    while (idx < expression.length())
    {
        if (expression[idx] == '+') func(0, str);
        else if (expression[idx] == '-') func(1, str);
        else if (expression[idx] == '*') func(2, str);
        else
        {
            str += expression[idx++];
            continue;
        }
            
        str = "";
        idx++;
    }
    
    DQ.push_back(stoll(str));
    
    for (int i = 0; i < 3; i++)
    {
        if (op[i]) cnt++;
    }
    
    solve(0);
    
    return answer;
}