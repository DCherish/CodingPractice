#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<char> vec;

unordered_map<string, int> umap;
int maxcnt = 0;

void solve(string str, int N, int depth, int idx)
{
    if (depth == N)
    {
        vector<char> temp = vec;
        
        sort(temp.begin(), temp.end());
        
        string s = "";
        
        for (int i = 0; i < temp.size(); i++)
        {
            s += temp[i];
        }
        
        umap[s] += 1;
        
        maxcnt = max(maxcnt, umap[s]);
        
        return;
    }
    
    for (int i = idx; i < str.length(); i++)
    {
        vec.push_back(str[i]);
        solve(str, N, depth + 1, i + 1);
        vec.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    for (int i = 0; i < course.size(); i++)
    {
        umap.clear();
        maxcnt = 0;
        
        for (int j = 0; j < orders.size(); j++)
        {
            solve(orders[j], course[i], 0, 0);
        }
        
        if (maxcnt == 1) continue;
        
        for (auto a : umap)
        {
            if (a.second == maxcnt)
            {
                answer.push_back(a.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}