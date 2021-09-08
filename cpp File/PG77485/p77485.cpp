#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MAP[101][101];

int do_rotate(int x1, int y1, int x2, int y2)
{
	int temp = MAP[x1][y1];

	int result = temp;

	for (int i = x1; i <= x2 - 1; i++)
	{
		MAP[i][y1] = MAP[i + 1][y1];

		result = min(result, MAP[i][y1]);
	}

	for (int i = y1; i <= y2 - 1; i++)
	{
		MAP[x2][i] = MAP[x2][i + 1];

		result = min(result, MAP[x2][i]);
	}

	for (int i = x2; i >= x1 + 1; i--)
	{
		MAP[i][y2] = MAP[i - 1][y2];

		result = min(result, MAP[i][y2]);
	}

	for (int i = y2; i >= y1 + 1; i--)
	{
		MAP[x1][i] = MAP[x1][i - 1];

		result = min(result, MAP[x1][i]);
	}

	MAP[x1][y1 + 1] = temp;

	return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
	vector<int> answer;

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= columns; j++)
		{
			MAP[i][j] = (i - 1) * columns + j;
		}
	}

	for (int i = 0; i < queries.size(); i++)
	{
		int x1 = queries[i][0];
		int y1 = queries[i][1];

		int x2 = queries[i][2];
		int y2 = queries[i][3];

		int result = do_rotate(x1, y1, x2, y2);

		answer.push_back(result);
	}

	return answer;
}