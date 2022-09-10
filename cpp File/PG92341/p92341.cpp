#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, int> in_umap;
unordered_map<string, int> out_umap;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.first < b.first;
}

int cnvert(string s)
{
    int result = 0;
    
    result += 60 * stoi(s.substr(0, 2));
    result += stoi(s.substr(3, 2));
    
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    
    for (int i = 0; i < records.size(); i++)
    {
        stringstream ss(records[i]);
        string token;
        
        vector<string> temp;
        
        while (getline(ss, token, ' '))
        {
            temp.push_back(token);
        }
        
        if (temp[2] == "IN")
        {
            in_umap[temp[1]] = cnvert(temp[0]);
        }
        else
        {
            out_umap[temp[1]] += (cnvert(temp[0]) - in_umap[temp[1]]);
            in_umap.erase(temp[1]);
        }
    }
    
    for (auto a : in_umap)
    {
        out_umap[a.first] += (cnvert("23:59") - a.second);
    }
    
    vector<pair<string, int>> vec(out_umap.begin(), out_umap.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].second <= fees[0]) answer.push_back(fees[1]);
        else
        {
            answer.push_back(fees[1] + ceil((double)(vec[i].second - fees[0]) / (double)fees[2]) * fees[3]);
        }
    }
    
    return answer;
}