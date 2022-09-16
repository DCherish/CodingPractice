#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> lane[31];
stack<int> basket;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    
    int sz = board.size();
    
    for (int i = 0; i < sz; i++)
    {
        for (int j = sz - 1; j >= 0; j--)
        {
            if (board[j][i] != 0) lane[i + 1].push(board[j][i]);
            else break;
        }
    }
    
    for (int i = 0; i < moves.size(); i++)
    {
        int idx = moves[i];
        
        if (!lane[idx].empty())
        {
            int num = lane[idx].top();
            lane[idx].pop();
            
            if (!basket.empty() && num == basket.top())
            {
                answer += 2;
                basket.pop();
            }
            else basket.push(num);
        }
    }
    
    return answer;
}