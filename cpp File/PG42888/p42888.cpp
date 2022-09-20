#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct info
{
    bool state;
    string id;
};

vector<info> vec;

unordered_map<string, string> umap;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string token;
        
        vector<string> temp;
        
        while (getline(ss, token, ' '))
        {
            temp.push_back(token);
        }
        
        if (temp[0] == "Enter")
        {
            umap[temp[1]] = temp[2];
            
            vec.push_back({ true, temp[1] });
        }
        else if (temp[0] == "Leave")
        {
            vec.push_back({ false, temp[1] });
        }
        else
        {
            umap[temp[1]] = temp[2];
        }
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        string str = umap[vec[i].id];
        
        if (vec[i].state) str += "님이 들어왔습니다.";
        else str += "님이 나갔습니다.";
        
        answer.push_back(str);
    }

    return answer;
}