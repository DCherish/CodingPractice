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