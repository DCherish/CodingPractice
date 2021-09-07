
#include <string>
#include <vector>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

bool check(int x, int y, vector<string> board)
{
	char idx = board[x][y];

	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (idx != board[nx][ny]) return false;
	}

	return true;
}

int solution(int m, int n, vector<string> board)
{
	int answer = 0;

	bool state = true;

	while (state)
	{
		state = false;

		vector<pnt> vec;

		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] == '.') continue;

				if (check(i, j, board) == true)
				{
					vec.push_back({ i, j });
					state = true;
				}
			}
		}

		if (state == true)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				int cx = vec[i].x;
				int cy = vec[i].y;

				if (board[cx][cy] != '.')
				{
					board[cx][cy] = '.';
					answer += 1;
				}

				for (int j = 0; j < 3; j++)
				{
					int nx = cx + dx[j];
					int ny = cy + dy[j];

					if (board[nx][ny] != '.')
					{
						board[nx][ny] = '.';
						answer += 1;
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				int idx = m - 1;

				for (int j = m - 1; j >= 0; j--)
				{
					if (board[j][i] != '.')
					{
						if (j != idx)
						{
							board[idx][i] = board[j][i];
							board[j][i] = '.';
						}

						idx--;
					}
				}
			}
		}
	}

	return answer;
}