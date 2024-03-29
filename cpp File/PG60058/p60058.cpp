#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

deque<char> DQ_u;
deque<char> DQ_v;

string u_func();
string v_func();

string u_func()
{
    string result = "";
    
    bool state = true;
    
    deque<char> DQ_t = DQ_u;
    
    stack<char> S;
    
    while (!DQ_u.empty())
    {
        char c = DQ_u.front();
        DQ_u.pop_front();
        
        if (c == '(') S.push(c);
        else
        {
            if (S.empty()) 
            {
                state = false;
                break;
            }
            else S.pop();
        }
    }
    
    if (state)
    {
        while (!DQ_t.empty())
        {
            char temp = DQ_t.front();
            DQ_t.pop_front();

            result += temp;
        }
    }
    else
    {
        DQ_u.clear();
        
        result += '(';
        result += v_func();
        result += ')';
        
        DQ_t.pop_front();
        DQ_t.pop_back();
        
        while (!DQ_t.empty())
        {
            char c = DQ_t.front();
            DQ_t.pop_front();
            
            if (c == '(') result += ')';
            else result += '(';
        }
    }
    
    return result;
}

string v_func()
{
    string result = "";
    
    int l_cnt = 0;
    int r_cnt = 0;
    
    while (!DQ_v.empty())
    {
        char c = DQ_v.front();
        DQ_v.pop_front();
        
        if (c == '(') l_cnt++;
        else r_cnt++;
        
        DQ_u.push_back(c);
        
        if (l_cnt == r_cnt)
        {
            result += u_func();
            
            l_cnt = 0;
            r_cnt = 0;
        }
    }
    
    return result;
}

string solution(string p)
{
    string answer = "";
    
    for (int i = 0; i < p.length(); i++)
    {
        DQ_v.push_back(p[i]);
    }
    
    answer += v_func();
    
    return answer;
}