#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
    int x;
    int y;
    int cost;
    int dir;
};

int N;

queue<info> Q;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS(vector<vector<int>> &board)
{
    int result = INT_MAX;
    
    vector<vector<vector<int>>> visited(4, vector<vector<int>>(N, vector<int>(N, INT_MAX)));
    
    visited[1][0][0] = 0;
    visited[3][0][0] = 0;
    
    Q.push({ 0, 0, 0, 1 });
    Q.push({ 0, 0, 0, 3 });
    
    while (!Q.empty())
    {
        int x = Q.front().x;
        int y = Q.front().y;
        int cost = Q.front().cost;
        int dir = Q.front().dir;
        Q.pop();
        
        if (x == N - 1 && y == N - 1)
        {
            result = min(result, cost);
            continue;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int nc = 0;
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            
            if (board[nx][ny] == 1) continue;
            
            if (dir == -1 || dir == i) nc = cost + 100;
            else nc = cost + 600;
            
            if (visited[i][nx][ny] > nc)
            {
                visited[i][nx][ny] = nc;
                Q.push({ nx, ny, nc, i });
            }
        }
    }
    
    return result;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    N = board.size();
    
    answer = BFS(board);
    
    return answer;
}