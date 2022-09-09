#include <string>
#include <vector>
#include <cctype>
#include <deque>
#include <unordered_set>

using namespace std;

deque<string> DQ;

unordered_set<string> uset;

void refresh_DQ(string s)
{
    for (int i = 0; i < DQ.size(); i++)
    {
        if (DQ[i] == s)
        {
            DQ.erase(DQ.begin() + i, DQ.begin() + i + 1);
            DQ.push_back(s);
            break;
        }
    }
}

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
    
    if (cacheSize == 0) return cities.size() * 5;
    
    for (int i = 0; i < cities.size(); i++)
    {
        string city = cnvert(cities[i]);
        
        if (uset.count(city) != 0)
        {
            answer += 1;
                
            refresh_DQ(city);
        }
        else
        {
            if (DQ.size() < cacheSize)
            {
                answer += 5;
                
                uset.insert(city);
                DQ.push_back(city);
            }
            else
            {
                answer += 5;
                
                uset.erase(DQ.front());
                DQ.pop_front();
                
                uset.insert(city);
                DQ.push_back(city);
            }
        }
    }
    
    return answer;
}