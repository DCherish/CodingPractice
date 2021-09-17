#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> vec[31];
vector<int> pick;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    int size = board.size();

    int cnt = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 0) continue;

            vec[j + 1].push_back(board[i][j]);
        }
    }

    for (int i = 0; i < moves.size(); i++)
    {
        int idx = moves[i];

        int sz = vec[idx].size();

        if (sz == 0) continue;
        else
        {
            int doll = vec[idx][sz - 1];

            vec[idx].pop_back();
            
            if (pick.size() == 0)
            {
                pick.push_back(doll);
            }
            else
            {
                int prev = pick[pick.size() - 1];

                if (prev == doll)
                {
                    pick.pop_back();
                    cnt++;
                }
                else
                {
                    pick.push_back(doll);
                }
            }
        }
    }

    answer = cnt;

    return answer;
}