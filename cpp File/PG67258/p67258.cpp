#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, int> umap;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    
    unordered_set<string> uset(gems.begin(), gems.end());
    
    int start = 0;
    int end = 0;
    
    int mincost = gems.size();
    int minstart = 0;
    int minend = 0;
    
    while (end < gems.size())
    {
        string str = gems[end];
        
        umap[str]++;
        
        if (umap.size() < uset.size()) end++;
        else
        {
            while (umap.size() == uset.size())
            {
                if (mincost > end - start)
                {
                    mincost = end - start;
                    minend = end;
                    minstart = start;
                }
                
                umap[gems[start]]--;
                
                if (umap[gems[start]] == 0)
                {
                    umap.erase(gems[start]);
                }
                
                start++;
            }
            
            end++;
        }
    }
    
    answer.push_back(minstart + 1);
    answer.push_back(minend + 1);
    
    return answer;
}