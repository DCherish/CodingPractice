#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct info
{
    string head;
    int num;
    int idx;
};

vector<info> vec;

bool cmp(info a, info b)
{
    if (a.head == b.head)
    {
        if (a.num == b.num)
        {
            return a.idx < b.idx;
        }
        else return a.num < b.num;
    }
    else return a.head < b.head;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    
    for (int i = 0; i < files.size(); i++)
    {
        string file = files[i];
        
        int idx = 0;
        
        string head = "";
        string num = "";
        
        for (int j = 0; j < file.length(); j++)
        {
            if (file[j] >= '0' && file[j] <= '9')
            {
                idx = j;
                break;
            }
            else head += tolower(file[j]);
        }
        
        for (int j = idx; j < file.length(); j++)
        {
            if (file[j] >= '0' && file[j] <= '9') num += file[j];
            else break;
        }
        
        vec.push_back({ head, stoi(num), i });
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(files[vec[i].idx]);
    }
    
    return answer;
}