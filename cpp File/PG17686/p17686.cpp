#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

struct info
{
    string head;
    int number;
    int idx;
};

vector<info> vec;

bool cmp(info a, info b)
{
    if (a.head == b.head)
    {
        if (a.number == b.number)
        {
            return a.idx < b.idx;
        }
        return a.number < b.number;
    }
    return a.head < b.head;
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

vector<string> solution(vector<string> files)
{
    vector<string> answer;
    
    for (int i = 0; i < files.size(); i++)
    {
        int x, y;
        int j;
        
        for (j = 0; j < files[i].length(); j++)
        {
            if (files[i][j] >= '0' && files[i][j] <= '9')
            {
                x = j;
                break;
            }
        }
        
        for (j = x; j < files[i].length(); j++)
        {
            if (files[i][j] < '0' || files[i][j] > '9')
            {
                break;
            }
        }
        
        y = j;
        
        string h = cnvert(files[i].substr(0, x));
        int n = stoi(files[i].substr(x, (y - x)));
        
        vec.push_back({ h, n, i });
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(files[vec[i].idx]);
    }
    
    return answer;
}