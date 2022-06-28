#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MAP[101][101];

void make_map(int r, int c)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            MAP[i][j] = c * (i - 1) + j;
        }
    }
}

int rotate_map(int x1, int y1, int x2, int y2)
{
    int result = MAP[x1][y2];
    int temp = result;
    
    for (int i = y2; i > y1; i--)
    {
        MAP[x1][i] = MAP[x1][i - 1];
        
        result = min(result, MAP[x1][i]);
    }
    
    for (int i = x1; i < x2; i++)
    {
        MAP[i][y1] = MAP[i + 1][y1];
        
        result = min(result, MAP[i][y1]);
    }
    
    for (int i = y1; i < y2; i++)
    {
        MAP[x2][i] = MAP[x2][i + 1];
        
        result = min(result, MAP[x2][i]);
    }
    
    for (int i = x2; i > x1; i--)
    {
        MAP[i][y2] = MAP[i - 1][y2];
        
        result = min(result, MAP[i][y2]);
    }
    
    MAP[x1 + 1][y2] = temp;
    
    return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    
    make_map(rows, columns);
    
    for (int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        int result = rotate_map(x1, y1, x2, y2);
        
        answer.push_back(result);
    }
    
    return answer;
}