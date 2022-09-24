#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isFinished(vector<vector<int>> &board, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (board[nx][ny] == 0) continue;
        
        return false;
    }
    
    return true;
}

pair<bool, int> solve(vector<vector<int>> &board, int x1, int y1, int x2, int y2)
{
    if (isFinished(board, x1, y1)) return { false, 0 };
    if (x1 == x2 && y1 == y2) return { true, 1 };
    
    bool state = false;
    
    int minCost = INT_MAX;
    int maxCost = 0;
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x1 + dx[i];
        int ny = y1 + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (board[nx][ny] == 0) continue;
        
        board[x1][y1] = 0;
        
        pair<bool, int> res = solve(board, x2, y2, nx, ny);
        
        board[x1][y1] = 1;
        
        if (!res.first) // 상대방이 졌다면
        {
            state = true; // 내가 무조건 이겼다고 표시
            minCost = min(minCost, res.second);
        }
        else if (!state) // 내가 아직 이겼는지 모르는 상태라면
        {
            maxCost = max(maxCost, res.second);
        }
    }
    
    if (state) return { state, minCost + 1 }; // 내가 이겼다면
    else return { state, maxCost + 1 }; // 내가 이기지 못했다면
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    int answer = 0;
    
    N = board.size();
    M = board[0].size();
    
    answer = solve(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
    
    return answer;
}