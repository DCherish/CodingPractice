#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> cntmap;
unordered_map<int, string> idxmap;

int len, num;
string order;

int maxcnt;

void DFS(int depth, int idx, string str)
{
    if (depth == len)
    {
        if (cntmap.count(str) == 0)
        {
            idxmap[num] = str;
            num++;
        }
        
        cntmap[str] += 1;
        
        maxcnt = max(maxcnt, cntmap[str]);
        
        return;
    }
    
    for (int i = idx; i < order.length(); i++)
    {
        DFS(depth + 1, i + 1, str + order[i]);
    }
}

string func(string str)
{
    vector<char> vec;
    
    for (int i = 0; i < str.length(); i++)
    {
        vec.push_back(str[i]);
    }
    
    sort(vec.begin(), vec.end());
    
    string result = "";
    
    for (int i = 0; i < vec.size(); i++)
    {
        result += vec[i];
    }
    
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    for (int i = 0; i < course.size(); i++)
    {
        len = course[i];
        
        cntmap.clear();
        idxmap.clear();
        
        num = 1;
        maxcnt = 0;
        
        for (int j = 0; j < orders.size(); j++)
        {
            order = func(orders[j]);
            DFS(0, 0, "");
        }
        
        for (int j = 1; j < num; j++)
        {
            if (cntmap[idxmap[j]] == maxcnt && cntmap[idxmap[j]] > 1)
            {
                answer.push_back(idxmap[j]);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}