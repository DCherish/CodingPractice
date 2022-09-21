#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> umap;
int maxcost = 0;

string cnvert(string s)
{
    string result = "";
    
    vector<char> temp;
    
    for (int i = 0; i < s.length(); i++)
    {
        temp.push_back(s[i]);
    }
    
    sort(temp.begin(), temp.end());
    
    for (int i = 0; i < temp.size(); i++)
    {
        result += temp[i];
    }
    
    return result;
}

void solve(int len, int depth, int idx, string str, string order)
{
    if (len == depth)
    {
        umap[str] += 1;
        
        maxcost = max(maxcost, umap[str]);
        
        return;
    }
    
    for (int i = idx; i < order.length(); i++)
    {
        solve(len, depth + 1, i + 1, str + order[i], order);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    for (int i = 0; i < course.size(); i++)
    {
        int len = course[i];
        
        umap.clear();
        maxcost = 0;
        
        for (int j = 0; j < orders.size(); j++)
        {
            string order = orders[j];
            
            if (len > order.length()) continue;
            
            solve(len, 0, 0, "", cnvert(order));
        }
        
        if (maxcost <= 1) continue;
        
        for (auto a : umap)
        {
            if (a.second == maxcost) answer.push_back(a.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}