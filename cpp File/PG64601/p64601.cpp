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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> board;
    vector<int> moves;

    board.push_back({0, 0, 0, 0, 0});
    board.push_back({0, 0, 1, 0, 3});
    board.push_back({0, 2, 5, 0, 1});
    board.push_back({4, 2, 4, 4, 2});
    board.push_back({3, 5, 1, 3, 1});

    moves.push_back(1);
    moves.push_back(5);
    moves.push_back(3);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(2);
    moves.push_back(5);
    moves.push_back(1);
    moves.push_back(4);
    moves.push_back(3);

    cout << solution(board, moves) << "\n";

    return 0;
}