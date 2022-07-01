#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    
    int maxw = 0;
    int maxh = 0;
    
    for (int i = 0; i < sizes.size(); i++)
    {
        int w, h;
        
        if (sizes[i][0] < sizes[i][1])
        {
            w = sizes[i][1];
            h = sizes[i][0];
        }
        else
        {
            w = sizes[i][0];
            h = sizes[i][1];
        }
        
        maxw = max(maxw, w);
        maxh = max(maxh, h);
    }
    
    answer = maxw * maxh;
    
    return answer;
}