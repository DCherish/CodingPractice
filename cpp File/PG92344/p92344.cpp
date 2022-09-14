#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    
    int N = board.size();
    int M = board[0].size();
    
    vector<vector<int>> sumvec(N + 1, vector<int>(M + 1, 0));
    
    for (int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0];
        
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        
        int degree = skill[i][5] * pow(-1, type);;
        
        sumvec[r1][c1] += degree;
        sumvec[r1][c2 + 1] -= degree;
        sumvec[r2 + 1][c1] -= degree;
        sumvec[r2 + 1][c2 + 1] += degree;
    }
    
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 1; j < M + 1; j++)
        {
            sumvec[i][j] += sumvec[i][j - 1];
        }
    }
    
    for (int i = 0; i < M + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            sumvec[j][i] += sumvec[j - 1][i];
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] + sumvec[i][j] >= 1) answer++;
        }
    }
    
    return answer;
}