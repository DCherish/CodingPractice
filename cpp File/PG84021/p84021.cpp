#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct pnt
{
    int x;
    int y;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool visited[51][51];
bool tableIdx[2501];

vector<vector<pnt>> blanks;
vector<vector<pnt>> shapes;

vector<vector<pnt>> afterBlanks;
vector<vector<pnt>> afterShapes;

vector<vector<vector<pnt>>> finalShapes;

vector<pnt> BFS(int x, int y, int target, vector<vector<int>> &input)
{
    vector<pnt> result;
    queue<pnt> Q;
    
    Q.push({x, y});
    visited[x][y] = true;
    
    result.push_back({x, y});

    while (!Q.empty())
    {
        int qx = Q.front().x;
        int qy = Q.front().y;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= input.size() || ny >= input.size()) continue;
            
            if (visited[nx][ny] || input[nx][ny] != target) continue;
            
            Q.push({nx, ny});
            visited[nx][ny] = true;
            
            result.push_back({nx, ny});
        }
    }
    return result;
}

vector<vector<pnt>> cnvert(vector<vector<pnt>> &input, int value)
{
    vector<vector<pnt>> result;

    for (int i = 0; i < input.size(); i++)
    {
        vector<pnt> temp;
        
        int minX = value;
        int minY = value;
        
        for (int j = 0; j < input[i].size(); j++)
        {
            minX = min(minX, input[i][j].x);
            minY = min(minY, input[i][j].y);
        }
        
        for (int j = 0; j < input[i].size(); j++)
        {
            temp.push_back({input[i][j].x - minX, input[i][j].y - minY});
        }
        
        result.push_back(temp);
    }
    
    return result;
}

vector<pnt> rotation(vector<pnt> input)
{
    vector<pnt> result;
    
    for (int i = 0; i < input.size(); i++)
    {
        int x = (-1) * input[i].y;
        int y = input[i].x;
        
        result.push_back({x, y});
    }
    
    return result;
}

bool cmp(pnt a, pnt b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    else return a.x < b.x;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;
    
    int sz = game_board.size();

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (game_board[i][j] == 0 && !visited[i][j])
            {
                blanks.push_back(BFS(i, j, 0, game_board));
            }
        }
    }
    
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (table[i][j] == 1 && !visited[i][j])
            {
                shapes.push_back(BFS(i, j, 1, table));
            }
        }
    }
    

    afterBlanks = cnvert(blanks, 100);
    for (int i = 0; i < afterBlanks.size(); i++)
    {
        sort(afterBlanks[i].begin(), afterBlanks[i].end(), cmp);
    }

    afterShapes = cnvert(shapes, 100);
    
    for (int i = 0; i < afterShapes.size(); i++)
    {
        vector<vector<pnt>> afterTemp;
        vector<pnt> shape = afterShapes[i];
        
        for (int j = 0; j < 4; j++)
        {
            vector<pnt> temp = rotation(shape);
            afterTemp.push_back(temp);
            shape = temp;
        }
        
        vector<vector<pnt>> afterRotation = cnvert(afterTemp, 0);
        for (int j = 0; j < afterRotation.size(); j++)
        {
            sort(afterRotation[j].begin(), afterRotation[j].end(), cmp);
        }
        
        finalShapes.push_back(afterRotation);
    }
    
    memset(tableIdx, false, sizeof(tableIdx));
    
    for (int i = 0; i < afterBlanks.size(); i++)
    {
        vector<pnt> blank = afterBlanks[i];
        bool state = false;
        
        for (int j = 0; j < finalShapes.size(); j++)
        {
            if (tableIdx[j]) continue;
            
            vector<vector<pnt>> rotationShapes = finalShapes[j];
            if (blank.size() != rotationShapes[0].size()) continue;
            
            for (int k = 0; k < rotationShapes.size(); k++)
            {
                bool flag = true;
                
                for (int l = 0; l < blank.size(); l++)
                {
                    pnt bp = blank[l];
                    pnt sp = rotationShapes[k][l];
                    
                    if (bp.x != sp.x || bp.y != sp.y)
                    {
                        flag = false;
                        break;
                    }
                }
                
                if (flag)
                {
                    state = true;
                    answer += blank.size();
                    break;
                }
            }
            
            if (state)
            {
                tableIdx[j] = true;
                break;
            }
        }
    }
    
    return answer;
}