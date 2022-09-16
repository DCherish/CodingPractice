#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dx[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int dy[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

int cal(int x, int y, int num)
{
    return abs(dx[num] - x) + abs(dy[num] - y);
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    
    int lx = 3;
    int ly = 0;
    
    int rx = 3;
    int ry = 2;
    
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";
            
            lx = dx[numbers[i]];
            ly = dy[numbers[i]];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";
            
            rx = dx[numbers[i]];
            ry = dy[numbers[i]];
        }
        else
        {
            if (cal(lx, ly, numbers[i]) < cal(rx, ry, numbers[i]))
            {
                answer += "L";
            
                lx = dx[numbers[i]];
                ly = dy[numbers[i]];
            }
            else if (cal(lx, ly, numbers[i]) > cal(rx, ry, numbers[i]))
            {
                answer += "R";
            
                rx = dx[numbers[i]];
                ry = dy[numbers[i]];
            }
            else
            {
                // if (hand.compare("left") == 0)
                if (hand == "left")
                {
                    answer += "L";
            
                    lx = dx[numbers[i]];
                    ly = dy[numbers[i]];
                }
                else
                {
                    answer += "R";
            
                    rx = dx[numbers[i]];
                    ry = dy[numbers[i]];
                }
            }
        }
    }
    
    return answer;
}