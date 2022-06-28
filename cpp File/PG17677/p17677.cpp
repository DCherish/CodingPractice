#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

vector<string> vec1;
vector<string> vec2;

unordered_map<string, int> umap1;
unordered_map<string, int> umap2;

unordered_set<string> visited;

double samecnt, totalcnt, percent;

string cnvert(string s)
{
    string result = "";
    
    for (int i = 0; i < s.length(); i++)
    {
        result += toupper(s[i]);
    }
    
    return result;
}

int solution(string str1, string str2)
{
    int answer = 0;
    
    string s1 = cnvert(str1);
    string s2 = cnvert(str2);
    
    for (int i = 0; i < s1.length() - 1; i++)
    {
        if ((s1[i] >= 'A' && s1[i] <= 'Z') &&
            (s1[i + 1] >= 'A' && s1[i + 1] <= 'Z'))
        {
            string temp = s1.substr(i, 2);
            
            if (umap1.count(temp) == 0)
            {
                vec1.push_back(temp);
            }
            
            umap1[temp] += 1;
        }
    }
    
    for (int i = 0; i < s2.length() - 1; i++)
    {
        if ((s2[i] >= 'A' && s2[i] <= 'Z') &&
            (s2[i + 1] >= 'A' && s2[i + 1] <= 'Z'))
        {
            string temp = s2.substr(i, 2);
            
            if (umap2.count(temp) == 0)
            {
                vec2.push_back(temp);
            }
            
            umap2[temp] += 1;
        }
    }
    
    for (int i = 0; i < vec1.size(); i++)
    {
        string word = vec1[i];
        
        if (visited.count(word) != 0) continue;
        
        visited.insert(word);
        
        if (umap2.count(word) != 0)
        {
            int mincnt = min(umap1[word], umap2[word]);
            samecnt += mincnt;
        }
    }
    
    visited.clear();
    
    for (int i = 0; i < vec1.size(); i++)
    {
        string word = vec1[i];
        
        if (visited.count(word) != 0) continue;
        
        visited.insert(word);
        
        if (umap2.count(word) != 0)
        {
            int maxcnt = max(umap1[word], umap2[word]);
            totalcnt += maxcnt;
        }
        else
        {
            totalcnt += umap1[word];
        }
    }
    
    for (int i = 0; i < vec2.size(); i++)
    {
        string word = vec2[i];
        
        if (visited.count(word) != 0) continue;
        
        totalcnt += umap2[word];
    }
    
    if (totalcnt == 0)
    {
        answer = 65536;
    }
    else
    {
        percent = samecnt / totalcnt * (double)65536;
        answer = (int)percent;
    }
    
    return answer;
}