#include <string>
#include <vector>

using namespace std;

int keysz = 0;
int locksz = 0;
int boardsz = 0;

vector<vector<int>> r_key;

void rotate_key()
{
    vector<vector<int>> key = r_key;
    
    r_key.clear();

    for (int i = 0; i < keysz; i++)
    {
        vector<int> temp;

        for (int j = keysz - 1; j >= 0; j--)
        {
            temp.push_back(key[j][i]);
        }
        
        r_key.push_back(temp);
    }
}

bool check(int x, int y, vector<vector<int>> board)
{
    int keysz = r_key.size();
    
    for (int i = x; i < x + keysz; i++)
    {
        for (int j = y; j < y + keysz; j++)
        {
            board[i][j] += r_key[i - x][j - y];
        }
    }
    
    for (int i = keysz - 1; i < keysz - 1 + locksz; i++)
    {
        for (int j = keysz - 1; j < keysz - 1 + locksz; j++)
        {
            if (board[i][j] != 1) return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    
    keysz = key.size();
    locksz = lock.size();
    boardsz = keysz * 2 + locksz - 2;
    
    vector<vector<int>> board(boardsz, vector<int>(boardsz));
    
    for (int i = keysz - 1; i < keysz - 1 + locksz; i++)
    {
        for (int j = keysz - 1; j < keysz - 1 + locksz; j++)
        {
            board[i][j] = lock[i - keysz + 1][j - keysz + 1];
        }
    }
    
    for (int i = 0; i < keysz; i++)
    {
        r_key.push_back(key[i]);
    }
    
    for (int r = 0; r < 4; r++)
    {
        for (int i = 0; i <= boardsz - keysz; i++)
        {
            for (int j = 0; j <= boardsz - keysz; j++)
            {
                if (check(i, j, board)) return true;
            }
        }

        rotate_key();
    }
    
    return answer;
}