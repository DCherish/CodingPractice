#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct pnt
{
    int x;
    int y;
};

pnt l, r;

int keyx[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
int keyy[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    l.x = 3;
    l.y = 0;

    r.x = 3;
    r.y = 2;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer += "L";

            l.x = keyx[numbers[i]];
            l.y = keyy[numbers[i]];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer += "R";

            r.x = keyx[numbers[i]];
            r.y = keyy[numbers[i]];
        }
        else
        {
            int ld = abs(keyx[numbers[i]] - l.x) + abs(keyy[numbers[i]] - l.y);
            int rd = abs(keyx[numbers[i]] - r.x) + abs(keyy[numbers[i]] - r.y);

            if (ld < rd)
            {
                answer += "L";

                l.x = keyx[numbers[i]];
                l.y = keyy[numbers[i]];
            }
            else if (ld > rd)
            {
                answer += "R";

                r.x = keyx[numbers[i]];
                r.y = keyy[numbers[i]];
            }
            else
            {
                // if (hand.compare("left") == 0)
                if (hand == "left")
                {
                    answer += "L";

                    l.x = keyx[numbers[i]];
                    l.y = keyy[numbers[i]];
                }
                else
                {
                    answer += "R";

                    r.x = keyx[numbers[i]];
                    r.y = keyy[numbers[i]];
                }
            }
        }
    }

    return answer;
}