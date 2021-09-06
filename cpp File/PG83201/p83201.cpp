#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool except_flag[10];

string cnvert(double avg)
{
	if (avg >= (double)90)
	{
		return "A";
	}
	else if (avg >= (double)80 && avg < (double)90)
	{
		return "B";
	}
	else if (avg >= (double)70 && avg < (double)80)
	{
		return "C";
	}
	else if (avg >= (double)50 && avg < (double)70)
	{
		return "D";
	}
	else return "F";
}

string solution(vector<vector<int>> scores)
{
	string answer = "";

	int N = scores.size();

	for (int i = 0; i < N; i++)
	{
		bool min_flag = false;
		bool max_flag = false;

		int min_score = 101;
		int max_score = -1;

		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				if (scores[j][i] < min_score)
				{
					min_flag = true;

					min_score = scores[j][i];
				}
				if (scores[j][i] > max_score)
				{
					max_flag = true;

					max_score = scores[j][i];
				}
			}
			else
			{
				if (scores[j][i] <= min_score)
				{
					min_flag = false;

					min_score = scores[j][i];
				}

				if (scores[j][i] >= max_score)
				{
					max_flag = false;

					max_score = scores[j][i];
				}
			}
		}

		if (min_flag == true || max_flag == true)
		{
			except_flag[i] = true;
			scores[i][i] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		double sum = 0;
		double avg = 0;
		double temp = 0;

		if (except_flag[i] == true) temp = 1;

		for (int j = 0; j < N; j++)
		{
			sum += (double)scores[j][i];
		}

		avg = sum / (double)(N - temp);

		answer += cnvert(avg);
	}

	return answer;
}