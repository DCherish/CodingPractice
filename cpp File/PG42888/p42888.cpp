#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct info
{
    int idx;
    string id;
};

unordered_map<string, string> umap;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<info> result;
    
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string token;
        vector<string> vec;
        
        while (getline(ss, token, ' '))
        {
            vec.push_back(token);
        }
        
        if (vec[0].compare("Enter") == 0)
        {
            umap[vec[1]] = vec[2];
            result.push_back({ 0, vec[1] });
        }
        else if (vec[0].compare("Leave") == 0)
        {
            result.push_back({ 1, vec[1] });
        }
        else
        {
            umap[vec[1]] = vec[2];
        }
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        string str;
        
        if (result[i].idx == 0)
        {
            str = umap[result[i].id] + "님이 들어왔습니다.";
        }
        else if (result[i].idx == 1)
        {
            str = umap[result[i].id] + "님이 나갔습니다.";
        }
        
        answer.push_back(str);
    }
    
    return answer;
}