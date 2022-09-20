#include <string>
#include <vector>
#include <deque>
#include <cctype>

using namespace std;

deque<string> DQ;

string cnvert(string s)
{
    string result = "";
    
    for (int i = 0; i < s.length(); i++)
    {
        result += tolower(s[i]);
    }
    
    return result;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    
    int sz = cities.size();
    
    if (cacheSize == 0) return 5 * sz;
    
    for (int i = 0; i < sz; i++)
    {
        int idx = -1;
        
        string city = cnvert(cities[i]);
        
        for (int j = 0; j < DQ.size(); j++)
        {
            if (DQ[j] == city)
            {
                idx = j;
                break;
            }
        }
        
        if (idx != -1)
        {
            DQ.erase(DQ.begin() + idx, DQ.begin() + idx + 1);
            answer += 1;
        }
        else answer += 5;
        
        if (DQ.size() == cacheSize) DQ.pop_front();
        
        DQ.push_back(city);
    }
    
    return answer;
}