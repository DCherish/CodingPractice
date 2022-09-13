#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    
    vector<int> vec(dungeons.size());
    
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = i;
    }
    
    do
    {
        int cnt = 0;
        int tempk = k;
        
        for (int i = 0; i < vec.size(); i++)
        {
            int idx = vec[i];
            
            if (tempk - dungeons[idx][0] >= 0)
            {
                tempk -= dungeons[idx][1];
                cnt++;
            }
            else break;
        }
        
        answer = max(answer, cnt);
        
    } while (next_permutation(vec.begin(), vec.end()));
    
    return answer;
}