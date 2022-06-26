#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> lane[31];
stack<int> basket;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = board.size() - 1; j >= 0; j--)
        {
            if (board[j][i] != 0)
            {
                lane[i + 1].push(board[j][i]);
            }
        }
    }
    
    for (int i = 0; i < moves.size(); i++)
    {
        int idx = moves[i];
        
        if (!lane[idx].empty())
        {
            int num = lane[idx].top();
            lane[idx].pop();
            
            if (!basket.empty() && basket.top() == num)
            {
                answer += 2;
                basket.pop();
            }
            else
            {
                basket.push(num);
            }
        }
    }
    
    return answer;
}