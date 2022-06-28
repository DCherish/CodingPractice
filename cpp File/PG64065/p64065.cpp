#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> umap;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;
    
    stringstream ss(s);
    string token;
    
    while (getline(ss, token, '}'))
    {
        if (token == "") break;
        
        string str = "";
        
        for (int i = 2; i < token.length(); i++)
        {
            if (token[i] >= '0' && token[i] <= '9')
            {
                str += token[i];
            }
            else
            {
                umap[stoi(str)] += 1;
                str = "";
            }
        }
        
        umap[stoi(str)] += 1;
    }
    
    vector<pair<int, int>> vec(umap.begin(), umap.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(vec[i].first);
    }
    
    return answer;
}