#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int dx[4] = { -1, 1, 0, 0 }; // »óÇÏÁÂ¿ì
int dy[4] = { 0, 0, -1, 1 };

int loc_x[10] = { 3, 0, 0, 0, 1, 1, 1, 2, 2, 2 };
int loc_y[10] = { 1, 0, 1, 2, 0, 1, 2, 0, 1, 2 };

pnt prev_left, prev_right;

int cal(int x, int y, int num)
{
	return abs(loc_x[num] - x) + abs(loc_y[num] - y);
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";

	prev_left.x = 3;
	prev_left.y = 0;

	prev_right.x = 3;
	prev_right.y = 2;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += "L";

			prev_left.x = loc_x[numbers[i]];
			prev_left.y = loc_y[numbers[i]];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += "R";

			prev_right.x = loc_x[numbers[i]];
			prev_right.y = loc_y[numbers[i]];
		}
		else
		{
			if (cal(prev_left.x, prev_left.y, numbers[i]) < cal(prev_right.x, prev_right.y, numbers[i]))
			{
				answer += "L";

				prev_left.x = loc_x[numbers[i]];
				prev_left.y = loc_y[numbers[i]];
			}
			else if (cal(prev_left.x, prev_left.y, numbers[i]) > cal(prev_right.x, prev_right.y, numbers[i]))
			{
				answer += "R";

				prev_right.x = loc_x[numbers[i]];
				prev_right.y = loc_y[numbers[i]];
			}
			else
			{
				if (hand.compare("left") == 0)
				{
					answer += "L";

					prev_left.x = loc_x[numbers[i]];
					prev_left.y = loc_y[numbers[i]];
				}
				else
				{
					answer += "R";

					prev_right.x = loc_x[numbers[i]];
					prev_right.y = loc_y[numbers[i]];
				}
			}
		}
	}

	return answer;
}