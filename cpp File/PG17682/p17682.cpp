#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct info
{
	int score;
	char bonus;
	int option;
};

int solution(string dartResult)
{
	int answer = 0;
	bool state = false;

	vector<info> vec;

	for (int i = 0; i < dartResult.length();)
	{
		int s = 0;

		while (dartResult[i] >= '0' && dartResult[i] <= '9')
		{
			s *= 10;
			s += (int)(dartResult[i] - '0');
			i++;
		}

		char b = dartResult[i];
		i++;

		int o = 0;

		if (dartResult[i] == '*')
		{
			o = 1;
			i++;
		}
		else if (dartResult[i] == '#')
		{
			o = 2;
			i++;
		}

		vec.push_back({ s, b, o });
	}

	vector<int> result(vec.size());

	for (int i = 0; i < vec.size(); i++)
	{
		int temp;

		if (vec[i].bonus == 'S')
		{
			temp = vec[i].score;
		}
		else if (vec[i].bonus == 'D')
		{
			temp = pow(vec[i].score, 2);
		}
		else if (vec[i].bonus == 'T')
		{
			temp = pow(vec[i].score, 3);
		}

		if (vec[i].option == 0)
		{
			result[i] = temp;
		}
		else if (vec[i].option == 1)
		{
			if (i - 1 >= 0)
			{
				result[i - 1] *= 2;
			}

			result[i] = temp;
			result[i] *= 2;
		}
		else if (vec[i].option == 2)
		{
			result[i] = (-1) * temp;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		answer += result[i];
	}

	return answer;
}