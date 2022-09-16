#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    double rate;
    int idx;
};

int iarr[510];
int carr[510];

vector<info> vec;

bool cmp(info a, info b)
{
    if (a.rate == b.rate)
    {
        return a.idx < b.idx;
    }
    else return a.rate > b.rate;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    
    for (int i = 0; i < stages.size(); i++)
    {
        int num = stages[i];
        
        iarr[num]++;
        
        carr[1]++;
        carr[num + 1]--;
    }
    
    for (int i = 2; i <= N; i++)
    {
        carr[i] += carr[i - 1];
    }
    
    for (int i = 1; i <= N; i++)
    {
        double temp;
        
        if (carr[i] == 0) temp = 0;
        else temp = (double)iarr[i] / (double)carr[i];
        
        vec.push_back({ temp, i });
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for (int i = 0; i < vec.size(); i++)
    {
        answer.push_back(vec[i].idx);
    }
    
    return answer;
}