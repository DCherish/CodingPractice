#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    
    string temp = "";
    
    for (int i = 0; i < new_id.length(); i++)
    {
        char c = new_id[i];
        
        if (c >= '0' && c <= '9') temp += c;
        else if (c >= 'A' && c <= 'Z') temp += tolower(c);
        else if (c >= 'a' && c <= 'z') temp += c;
        else if (c == '-' || c == '_' || c == '.') temp += c;
    }
    
    new_id = temp;
    temp = "";
    
    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] == '.')
        {
            while (i < new_id.length() && new_id[i] == '.')
            {
                i++;
            }
            
            temp += '.';
            i--;
        }
        else temp += new_id[i];
    }
    
    new_id = temp;
    temp = "";
    
    if (new_id[0] == '.') new_id = new_id.substr(1);
    
    if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    
    if (new_id == "") new_id = "a";
    
    if (new_id.length() >= 16)
    {
        new_id = new_id.substr(0, 15);
        
        if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    }
    
    if (new_id.length() <= 2)
    {
        while (new_id.length() < 3)
        {
            new_id += new_id[new_id.length() - 1];
        }
    }
    
    answer = new_id;
    
    return answer;
}