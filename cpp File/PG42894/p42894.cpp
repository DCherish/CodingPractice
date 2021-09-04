#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt;
int N;
int MAP[50][50];
bool visited[201];

void removeMap(int x, int y, int idx)
{
	if (idx == 1)
	{
		for (int i = x - 2; i <= x; i++)
		{
			for (int j = y; j <= y + 1; j++)
			{
				MAP[i][j] = -1;
			}
		}
	}
	else if (idx == 2)
	{
		for (int i = x; i <= x + 2; i++)
		{
			for (int j = y; j <= y + 1; j++)
			{
				MAP[i][j] = -1;
			}
		}
	}
	else if (idx == 3)
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y; j <= y + 1; j++)
			{
				MAP[i][j] = -1;
			}
		}
	}
	else if (idx == 4)
	{
		for (int i = x; i <= x + 1; i++)
		{
			for (int j = y; j <= y + 2; j++)
			{
				MAP[i][j] = -1;
			}
		}
	}
	else if (idx == 5)
	{
		for (int i = x - 1; i <= x; i++)
		{
			for (int j = y; j <= y + 2; j++)
			{
				MAP[i][j] = -1;
			}
		}
	}
}

int check(int x, int y, int idx)
{
	if (x == 0)
	{
		if (y + 1 == N - 1)
		{
			if (MAP[x + 1][y] == -1 && MAP[x + 2][y] == -1) return 2;
			else return -1;
		}
		else
		{
			if (MAP[x][y + 2] == idx)
			{
				if (MAP[x + 1][y] == -1 && MAP[x + 1][y + 1] == -1) return 4;
				else return -1;
			}
			else
			{
				if (MAP[x + 1][y] == -1 && MAP[x + 2][y] == -1) return 2;
				else return -1;
			}
		}
	}
	else if (x == 1)
	{
		if (y + 1 == N - 1)
		{
			if (MAP[x + 2][y + 1] == idx)
			{
				if (MAP[x + 1][y] == -1 && MAP[x + 2][y] == -1) return 2;
				else return -1;
			}
			else
			{
				if (MAP[x - 1][y] == -1 && MAP[x + 1][y] == -1) return 3;
				else return -1;
			}
		}
		else
		{
			if (MAP[x][y + 2] == idx)
			{
				if (MAP[x + 1][y + 2] == idx)
				{
					if (MAP[x + 1][y] == -1 && MAP[x + 1][y + 1] == -1) return 4;
					else return -1;
				}
				else
				{
					if (MAP[x - 1][y] == -1 && MAP[x - 1][y + 1] == -1) return 5;
					else return -1;
				}
			}
			else
			{
				if (MAP[x + 2][y + 1] == idx)
				{
					if (MAP[x + 1][y] == -1 && MAP[x + 2][y] == -1) return 4;
					else return -1;
				}
				else
				{
					if (MAP[x - 1][y] == -1 && MAP[x + 1][y] == -1) return 3;
					else return -1;
				}
			}
		}
	}
	else if (x == N - 1)
	{
		if (y + 1 == N - 1)
		{
			if (MAP[x - 1][y] == -1 && MAP[x - 2][y] == -1) return 1;
			else return -1;
		}
		else
		{
			if (MAP[x][y + 2] == idx)
			{
				if (MAP[x - 1][y] == -1 && MAP[x - 1][y + 1] == -1) return 5;
				else return -1;
			}
			else
			{
				if (MAP[x - 1][y] == -1 && MAP[x - 2][y] == -1) return 1;
				else return -1;
			}
		}
	}
	else if (x == N - 2)
	{
		if (y + 1 == N - 1)
		{
			if (MAP[x - 2][y + 1] == idx)
			{
				if (MAP[x - 1][y] == -1 && MAP[x - 2][y] == -1) return 1;
				else return -1;
			}
			else
			{
				if (MAP[x - 1][y] == -1 && MAP[x + 1][y] == -1) return 3;
				else return -1;
			}
		}
		else
		{
			if (MAP[x][y + 2] == idx)
			{
				if (MAP[x - 1][y + 2] == idx)
				{
					if (MAP[x - 1][y] == -1 && MAP[x - 1][y + 1] == -1) return 5;
					else return -1;

				}
				else
				{
					if (MAP[x + 1][y] == -1 && MAP[x + 1][y + 1] == -1) return 4;
					else return -1;
				}
			}
			else
			{
				if (MAP[x - 2][y + 1] == idx)
				{
					if (MAP[x - 1][y] == -1 && MAP[x - 2][y] == -1) return 1;
					else return -1;
				}
				else
				{
					if (MAP[x - 1][y] == -1 && MAP[x + 1][y] == -1) return 3;
					else return -1;
				}
			}
		}
	}
	else
	{
		if (y + 1 == N - 1)
		{
			if (MAP[x - 2][y + 1] == idx)
			{
				if (MAP[x - 1][y] == -1 && MAP[x - 2][y] == -1) return 1;
				else return -1;
			}
			else if (MAP[x + 2][y + 1] == idx)
			{
				if (MAP[x + 1][y] == -1 && MAP[x + 2][y] == -1) return 2;
				else return -1;
			}
			else
			{
				if (MAP[x - 1][y] == -1 && MAP[x + 1][y] == -1) return 3;
				else return -1;
			}
		}
		else
		{
			if (MAP[x][y + 2] == idx)
			{
				if (MAP[x - 1][y + 2] == idx)
				{
					if (MAP[x - 1][y] == -1 && MAP[x - 1][y + 1] == -1) return 5;
					else return -1;

				}
				else
				{
					if (MAP[x + 1][y] == -1 && MAP[x + 1][y + 1] == -1) return 4;
					else return -1;
				}
			}
			else
			{
				if (MAP[x - 2][y + 1] == idx)
				{
					if (MAP[x - 1][y] == -1 && MAP[x - 2][y] == -1) return 1;
					else return -1;
				}
				else if (MAP[x + 2][y + 1] == idx)
				{
					if (MAP[x + 1][y] == -1 && MAP[x + 2][y] == -1) return 2;
					else return -1;
				}
				else
				{
					if (MAP[x - 1][y] == -1 && MAP[x + 1][y] == -1) return 3;
					else return -1;
				}
			}
		}
	}
}

void findBlock()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] >= 1)
			{
				if (visited[MAP[i][j]] == false)
				{
					visited[MAP[i][j]] = true;

					int num = check(i, j, MAP[i][j]);

					if (num != -1)
					{
						removeMap(i, j, num);
						cnt++;
					}
				}
			}
		}
	}
}

void fillMap()
{
	for (int j = 0; j < N; j++)
	{
		int temp = 0;

		for (int i = 0; i < N; i++)
		{
			temp = i;

			if (MAP[i][j] != 0) break;
		}

		for (int i = 0; i < temp; i++)
		{
			MAP[i][j] = -1;
		}
	}
}

int solution(vector<vector<int>> board)
{
	int answer = 0;

	memset(visited, false, sizeof(visited));

	N = board.size();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = board[i][j];
		}
	}

	fillMap();
	findBlock();

	answer = cnt;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> board;

	board.resize(10);

	for (int i = 0; i < board.size(); i++)
	{
		board[i].resize(10);
	}

	board = {{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,4,0,0,0},
			{0,0,0,0,0,4,4,0,0,0},
			{0,0,0,0,3,0,4,0,0,0},
			{0,0,0,2,3,0,0,0,5,5},
			{1,2,2,2,3,3,0,0,0,5},
			{1,1,1,0,0,0,0,0,0,5}};

	cout << solution(board) << "\n";

	return 0;
}