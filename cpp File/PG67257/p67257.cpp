#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

bool op[3];
int cnt = 0;

bool visited[3];

vector<int> opvec;

deque<ll> DQ;

ll answer = 0;

ll cal()
{
    deque<ll> DQ_copy = DQ;
    
    for (int i = 0; i < cnt; i++)
    {
        int j = 1;
        
        while (j < DQ_copy.size())
        {
            if (DQ_copy[j] == opvec[i])
            {
                if (opvec[i] == 0)
                {
                    DQ_copy[j - 1] += DQ_copy[j + 1];
                    DQ_copy.erase(DQ_copy.begin() + j, DQ_copy.begin() + j + 2);
                }
                else if (opvec[i] == 1)
                {
                    DQ_copy[j - 1] -= DQ_copy[j + 1];
                    DQ_copy.erase(DQ_copy.begin() + j, DQ_copy.begin() + j + 2);
                }
                else
                {
                    DQ_copy[j - 1] *= DQ_copy[j + 1];
                    DQ_copy.erase(DQ_copy.begin() + j, DQ_copy.begin() + j + 2);
                }
            }
            else j += 2;
        }
    }
    
    return abs(DQ_copy.front());
}

void solve(int depth)
{
    if (cnt == depth)
    {
        answer = max(answer, cal());
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (!op[i]) continue;
        if (visited[i]) continue;
        
        visited[i] = true;
        opvec.push_back(i);
        
        solve(depth + 1);
        
        opvec.pop_back();
        visited[i] = false;
    }
}

ll solution(string expression)
{
    for (int i = 0; i < expression.length();)
    {
        if (expression[i] == '+')
        {
            op[0] = true;
            DQ.push_back(0);
            i++;
        }
        else if (expression[i] == '-')
        {
            op[1] = true;
            DQ.push_back(1);
            i++;
        }
        else if (expression[i] == '*')
        {
            op[2] = true;
            DQ.push_back(2);
            i++;
        }
        else
        {
            ll num = 0;
            
            while (expression[i] >= '0' && expression[i] <= '9')
			{
                num *= 10;
                num += (ll)(expression[i] - '0');
				i++;
			}

			DQ.push_back(num);
        }
    }

	for (int i = 0; i < 3; i++)
	{
		if (op[i]) cnt++;
	}

	solve(0);
    
    return answer;
}