#include <string>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool check(int th, int x, int y, vector<vector<string>> places)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

		if (places[th][nx][ny] == 'P') return false;
		else if (places[th][nx][ny] == 'O')
		{
			for (int j = 0; j < 4; j++)
			{
				int nnx = nx + dx[j];
				int nny = ny + dy[j];

				if (nnx < 0 || nny < 0 || nnx >= 5 || nny >= 5) continue;

				if (nnx == x && nny == y) continue;
				else
				{
					if (places[th][nnx][nny] == 'P') return false;
				}
			}
		}
	}

	return true;
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;

	for (int i = 0; i < 5; i++)
	{
		bool state = true;

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (places[i][j][k] == 'P')
				{
					if (check(i, j, k, places) == false)
					{
						state = false;
						break;
					}
				}
			}

			if (state == false) break;
		}

		if (state == false) answer.push_back(0);
		else answer.push_back(1);
	}

	return answer;
}