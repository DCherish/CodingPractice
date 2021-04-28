#include <string>
#include <vector>

using namespace std;

int keysz, locksz, boardsz;

vector<vector<int>> r_key;

void rotate_key(vector<vector<int>> key)
{
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

bool put_key(int x, int y, vector<vector<int>> key, vector<vector<int>> board)
{
    for (int i = x; i < x + keysz; i++)
    {
        for (int j = y; j < y + keysz; j++)
        {
            board[i][j] += key[i - x][j - y];
        }
    }

    for (int i = keysz - 1; i <= boardsz - keysz; i++)
    {
        for (int j = keysz - 1; j <= boardsz - keysz; j++)
        {
            if (board[i][j] == 1) continue;

            return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;

    keysz = key.size();
    locksz = lock.size();
    boardsz = locksz + (keysz - 1) * 2;

    //vector<int> temp(5, 3);
    vector<vector<int>> board(boardsz, vector<int>(boardsz, 0));
    // 벡터 직접 접근 및 초기화

    for (int i = keysz - 1; i <= boardsz - keysz; i++)
    {
        for (int j = keysz - 1; j <= boardsz - keysz; j++)
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
            for (int j = 0; j < boardsz - keysz; j++)
            {
                if (put_key(i, j, r_key, board))
                {
                    answer = true;
                    return answer;
                }
            }
        }

        rotate_key(r_key);
    }

    return answer;
}