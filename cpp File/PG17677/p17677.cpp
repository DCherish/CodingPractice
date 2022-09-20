#include <string>
#include <cctype>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> umap1;
unordered_map<string, int> umap2;

bool isValid(char c)
{
    if (c >= 'a' && c <= 'z') return true;
    else if (c >= 'A' && c <= 'Z') return true;
    
    return false;
}

int solution(string str1, string str2)
{
    int answer = 0;
    
    int mincnt = 0;
    int maxcnt = 0;
    
    for (int i = 0; i < str1.length() - 1; i++)
    {
        string str = "";
        
        if (isValid(str1[i]) && isValid(str1[i + 1]))
        {
            str += toupper(str1[i]);
            str += toupper(str1[i + 1]);
            
            umap1[str] += 1;
        }
    }
    
    for (int i = 0; i < str2.length() - 1; i++)
    {
        string str = "";
        
        if (isValid(str2[i]) && isValid(str2[i + 1]))
        {
            str += toupper(str2[i]);
            str += toupper(str2[i + 1]);
            
            umap2[str] += 1;
        }
    }
    
    for (auto a : umap1)
    {
        if (umap2.count(a.first) != 0)
        {
            mincnt += min(umap1[a.first], umap2[a.first]);
        }
    }
    
    for (auto a : umap1)
    {
        if (umap2.count(a.first) == 0)
        {
            maxcnt += umap1[a.first];
        }
        else
        {
            maxcnt += max(umap1[a.first], umap2[a.first]);
            
            umap2.erase(a.first);
        }
    }
    
    for (auto a : umap2)
    {
        maxcnt += umap2[a.first];
    }
    
    if (mincnt == 0 && maxcnt == 0) return 65536;
    
    double result = 0;
    
    result = (double)mincnt / (double)maxcnt;
    result *= 65536;
    
    answer = (int)result;
    
    return answer;
}