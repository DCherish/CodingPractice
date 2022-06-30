#include <string>
#include <vector>
#include <deque>
#include <unordered_set>
#include <cctype>

using namespace std;

unordered_set<string> uset;

deque<string> DQ;

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

string cnvert(string str)
{
    string result = "";
    
    for (int i = 0; i < str.length(); i++)
    {
        result += tolower(str[i]);
    }
    
    return result;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    
    for (int i = 0; i < cities.size(); i++)
    {
        string city = cnvert(cities[i]);
        
        if (DQ.size() < cacheSize)
        {
            if (uset.count(city) != 0)
            {
                answer += 1;
                
                refresh_DQ(city);
            }
            else
            {
                answer += 5;
                
                DQ.push_back(city);
                uset.insert(city);
            }
        }
        else if (DQ.size() == cacheSize)
        {
            if (uset.count(city) != 0)
            {
                answer += 1;
                
                refresh_DQ(city);
            }
            else
            {
                answer += 5;
                
                uset.erase(DQ.front());
                DQ.pop_front();
                
                DQ.push_back(city);
                uset.insert(city);
            }
        }
    }
    
    return answer;
}