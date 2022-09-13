#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words)
{
    int answer = 0;
    
    sort(words.begin(), words.end());
    
    string pre_str = words[0];
    answer += 1;
    
    int pre = 0;
    
    for (int i = 1; i < words.size(); i++)
    {   
        int temp = 0;
            
        for (int j = 0; j < words[i].length(); j++)
        {
            temp = j;
            
            if (j >= pre_str.length())
            {
                answer += (pre_str.length() - pre - 1);
                answer += (j + 1);
                break;
            }
            
            if (words[i][j] != pre_str[j])
            {
                if (j > pre) answer += (j - pre);
                
                answer += (j + 1);
                break;
            }
        }
        
        pre = temp;
        pre_str = words[i];
    }
    
    return answer;
}