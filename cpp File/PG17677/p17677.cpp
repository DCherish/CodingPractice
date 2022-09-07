#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> umap1;
unordered_map<string, int> umap2;

int solution(string str1, string str2)
{
    int answer = 0;
    
    for (int i = 0; i < str1.length() - 1; i++)
    {
        char a = toupper(str1[i]);
        char b = toupper(str1[i + 1]);
        
        if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
        {
            string str = "";
            
            str += a;
            str += b;
            
            umap1[str] += 1;
        }
    }
    
    for (int i = 0; i < str2.length() - 1; i++)
    {
        char a = toupper(str2[i]);
        char b = toupper(str2[i + 1]);
        
        if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
        {
            string str = "";
            
            str += a;
            str += b;
            
            umap2[str] += 1;
        }
    }
    
    int mincnt = 0;
    int maxcnt = 0;
    
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