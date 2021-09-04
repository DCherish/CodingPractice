#include <string>
#include <vector>

using namespace std;

int N;
int dx[5][6], dy[5][6];

void pre_setting()
{
	// 0 1 2 3 4 ; only 5 figure
	// 0 1 2 3 ; color pnt // 4 5 ; black pnt

	dx[0][0] = 0; dx[0][1] = 1; dx[0][2] = 1; dx[0][3] = 1; dx[0][4] = 0; dx[0][5] = 0;
	dy[0][0] = 0; dy[0][1] = 0; dy[0][2] = 1; dy[0][3] = 2; dy[0][4] = 1; dy[0][5] = 2;

	dx[1][0] = 0; dx[1][1] = 1; dx[1][2] = 2; dx[1][3] = 2; dx[1][4] = 0; dx[1][5] = 1;
	dy[1][0] = 0; dy[1][1] = 0; dy[1][2] = 0; dy[1][3] = -1; dy[1][4] = -1; dy[1][5] = -1;

	dx[2][0] = 0; dx[2][1] = 1; dx[2][2] = 2; dx[2][3] = 2; dx[2][4] = 0; dx[2][5] = 1;
	dy[2][0] = 0; dy[2][1] = 0; dy[2][2] = 0; dy[2][3] = 1; dy[2][4] = 1; dy[2][5] = 1;

	dx[3][0] = 0; dx[3][1] = 1; dx[3][2] = 1; dx[3][3] = 1; dx[3][4] = 0; dx[3][5] = 0;
	dy[3][0] = 0; dy[3][1] = 0; dy[3][2] = -1; dy[3][3] = -2; dy[3][4] = -1; dy[3][5] = -2;

	dx[4][0] = 0; dx[4][1] = dx[4][2] = dx[4][3] = 1; dx[4][4] = 0; dx[4][5] = 0;
	dy[4][0] = 0; dy[4][1] = -1; dy[4][2] = 0; dy[4][3] = 1; dy[4][4] = -1; dy[4][5] = 1;
}

int check(int x, int y, vector<vector<int>> board)
{
	int value = board[x][y];

	for (int i = 0; i < 5; i++) // 다섯개 중 해당하는지?
	{
		bool state = true;

		for (int j = 0; j < 4; j++) // 좌표 비교
		{
			int nx = x + dx[i][j];
			int ny = y + dy[i][j];

			if ((nx < 0 || ny < 0 || nx >= N || ny >= N) || board[nx][ny] != value)
			{
				state = false;
				break;
			}
		}

		if (state == true) // 해당하는 경우
		{
			bool state2 = true;

			for (int j = 4; j < 6; j++)
			{
				int nx = x + dx[i][j];
				int ny = y + dy[i][j];

				if ((nx < 0 || ny < 0 || nx >= N || ny >= N) || board[nx][ny] != 0)
				{
					state2 = false;
					break;
				}

				for (int k = nx; k >= 0; k--) // 해당좌표까지 가로막는 도형 있는지 check
				{
					if (board[k][ny] != 0)
					{
						state2 = false;
						break;
					}
				}

				if (state2 == false) break;
			}

			if (state2 == true) return i;
		}
	}
	return -1;
}

void removeBoard(int x, int y, int Idx, vector<vector<int>>& board)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[Idx][i];
		int ny = y + dy[Idx][i];

		board[nx][ny] = 0;
	}
}

int solution(vector<vector<int>> board)
{
	int answer = 0;

	pre_setting();
	N = board.size();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0) continue;

			int result = check(i, j, board);

			if (result != -1)
			{
				removeBoard(i, j, result, board);
				answer++;
				j = -1;
			}
		}
	}

	return answer;
}