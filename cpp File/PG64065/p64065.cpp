#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> umap;

bool cmp(pair<int, int> a, pair<int, int> b)
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
        
        stringstream ss2(token.substr(2));
        string token2;
        
        while (getline(ss2, token2, ','))
        {
            umap[stoi(token2)] += 1;
        }
    }
    
    vector<pair<int, int>> vec(umap.begin(), umap.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(vec[i].first);
    }
    
    return answer;
}