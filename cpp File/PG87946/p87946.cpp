#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[8];

int result = 0;

void DFS(int k, int cnt, vector<vector<int>> &dungeons)
{   
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i]) continue;
        
        if (k - dungeons[i][0] >= 0)
        {
            visited[i] = true;
            result = max(result, cnt + 1);
            DFS(k - dungeons[i][1], cnt + 1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    
    DFS(k, 0, dungeons);
    
    answer = result;
    
    return answer;
}


// 풀이 2
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