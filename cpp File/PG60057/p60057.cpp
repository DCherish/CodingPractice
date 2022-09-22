#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = s.length();
    
    int len = s.length() / 2;
    
    for (int i = 1; i <= len; i++)
    {
        string prev = s.substr(0, i);
        
        int temp = 0;
        int cnt = 1;
        
        for (int j = i; j < s.length(); j += i)
        {
            string curr = s.substr(j, i);
            
            if (prev == curr) cnt++;
            else
            {
                if (cnt != 1)
                {
                    temp += to_string(cnt).length();
                    cnt = 1;
                }
                
                temp += prev.length();
                prev = curr;
            }
        }
        
        if (cnt != 1) temp += to_string(cnt).length();
        
        temp += prev.length();
        
        answer = min(answer, temp);
    }
    
    return answer;
}