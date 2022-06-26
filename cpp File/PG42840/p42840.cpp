#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[3];

int arr1[] = { 1, 2, 3, 4, 5 };
int arr2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int arr3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    
    for (int i = 0; i < answers.size(); i++)
    {
        int num = answers[i];
        
        if (arr1[i % 5] == num)
        {
            cnt[0]++;
        }
        
        if (arr2[i % 8] == num)
        {
            cnt[1]++;
        }
        
        if (arr3[i % 10] == num)
        {
            cnt[2]++;
        }
    }
    
    int maxcnt = max({cnt[0], cnt[1], cnt[2]});
    
    for (int i = 0; i < 3; i++)
    {
        if (maxcnt == cnt[i])
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}