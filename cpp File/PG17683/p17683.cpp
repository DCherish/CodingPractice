#include <string>
#include <vector>
#include <sstream>

using namespace std;

int maxcost = 0;

bool cmp(string a, string b)
{
    for (int i = 0; i < b.length(); i++)
    {
        int cnt = 0;
        
        while (true)
        {
            if (a[cnt] == b[i + cnt] && i + cnt < b.length())
            {
                cnt++;
                
                if (cnt == a.length())
                {
                    if (i + cnt == b.length()) return true;
                    if (b[i + cnt] != '#') return true;
                    
                    break;
                }
            }
            else break;
        }
    }
    
    return false;
}

int cnvert(string s)
{
    int result = 0;
    
    result += 60 * stoi(s.substr(0, 2));
    result += stoi(s.substr(3, 2));
    
    return result;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    
    for (int i = 0; i < musicinfos.size(); i++)
    {
        stringstream ss(musicinfos[i]);
        string token;
        
        vector<string> temp;
        
        while (getline(ss, token, ','))
        {
            temp.push_back(token);
        }
        
        int start = cnvert(temp[0]);
        int end = cnvert(temp[1]);
        
        string music = "";
        
        int idx = 0;
        int sharp_cnt = 0;
        
        for (int j = 0; j < end - start + sharp_cnt; j++)
        {
            music += temp[3][idx];
            idx++;
            
            if (idx == temp[3].length()) idx = 0;
            
            if (temp[3][idx] == '#') sharp_cnt++;
        }
        
        if (cmp(m, music))
        {
            if (end - start > maxcost)
            {
                maxcost = end - start;
                
                answer = temp[2];
            }
        }
    }
    
    return answer;
}