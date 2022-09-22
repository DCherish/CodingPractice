#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int maxcost = 0;

bool cmp(string a, string b)
{
    for (int i = 0; i < b.length(); i++)
    {
        int j = 0;
        
        while (i + j < b.length() && a[j] == b[i + j])
        {
            j++;
            
            if (j == a.length())
            {
                if (i + j == b.length()) return true;
                if (b[i + j] != '#') return true;
                
                break;
            }
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
        
        vector<string> vec;
        
        while (getline(ss, token, ','))
        {
            vec.push_back(token);
        }
        
        int s = cnvert(vec[0]);
        int e = cnvert(vec[1]);
        
        int playtime = e - s;
        
        string title = vec[2];
        
        string music = "";
        
        int scnt = 0;
        int idx = 0;
        
        for (int j = 0; j < playtime + scnt; j++)
        {
            music += vec[3][idx];
            idx++;
            
            if (idx == vec[3].length()) idx = 0;
            else if (vec[3][idx] == '#') scnt++;
        }
        
        if (cmp(m, music))
        {
            if (playtime > maxcost)
            {
                maxcost = playtime;
                answer = title;
            }
        }
    }
    
    return answer;
}