#include <iostream>
#include <deque>

using namespace std;

int N;
int maxnum = 2;

int board[20][20];

void up()
{
	for (int a = 0; a < N; a++)
	{
		deque<int> Q;

		int temp = 0;

		for (int b = 0; b < N; b++)
		{
			if (board[b][a] == 0) continue;

			if (temp != board[b][a])
			{
				temp = board[b][a];
				Q.push_back(board[b][a]);
				board[b][a] = 0;
			}
			else
			{
				Q.pop_back();
				Q.push_back(temp * 2);
				board[b][a] = 0;
				temp = 0;
			}
		}

		int idx = 0;

		while (!Q.empty())
		{
			int num = Q.front();
			Q.pop_front();

			board[idx][a] = num;
			idx++;
		}
	}
}

void down()
{
	for (int a = 0; a < N; a++)
	{
		deque<int> Q;

		int temp = 0;

		for (int b = N - 1; b >= 0; b--)
		{
			if (board[b][a] == 0) continue;

			if (temp != board[b][a])
			{
				temp = board[b][a];
				Q.push_back(board[b][a]);
				board[b][a] = 0;
			}
			else
			{
				Q.pop_back();
				Q.push_back(temp * 2);
				board[b][a] = 0;
				temp = 0;
			}
		}

		int idx = N - 1;

		while (!Q.empty())
		{
			int num = Q.front();
			Q.pop_front();

			board[idx][a] = num;
			idx--;
		}
	}
}

void left()
{
	for (int a = 0; a < N; a++)
	{
		deque<int> Q;

		int temp = 0;

		for (int b = 0; b < N; b++)
		{
			if (board[a][b] == 0) continue;

			if (temp != board[a][b])
			{
				temp = board[a][b];
				Q.push_back(board[a][b]);
				board[a][b] = 0;
			}
			else
			{
				Q.pop_back();
				Q.push_back(temp * 2);
				board[a][b] = 0;
				temp = 0;
			}
		}

		int idx = 0;

		while (!Q.empty())
		{
			int num = Q.front();
			Q.pop_front();

			board[a][idx] = num;
			idx++;
		}
	}
}

void right()
{
	for (int a = 0; a < N; a++)
	{
		deque<int> Q;

		int temp = 0;

		for (int b = N - 1; b >= 0; b--)
		{
			if (board[a][b] == 0) continue;

			if (temp != board[a][b])
			{
				temp = board[a][b];
				Q.push_back(board[a][b]);
				board[a][b] = 0;
			}
			else
			{
				Q.pop_back();
				Q.push_back(temp * 2);
				board[a][b] = 0;
				temp = 0;
			}
		}

		int idx = N - 1;

		while (!Q.empty())
		{
			int num = Q.front();
			Q.pop_front();

			board[a][idx] = num;
			idx--;
		}
	}
}

void function(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 0)
				{
					continue;
				}
				else if (board[i][j] > maxnum)
				{
					maxnum = board[i][j];
				}
			}
		}

		return;
	}

	int copyboard[20][20];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyboard[i][j] = board[i][j];
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (i == 1) // up
		{
			up();
		}
		else if (i == 2) // down
		{
			down();
		}
		else if (i == 3) // left
		{
			left();
		}
		else if (i == 4) // right
		{
			right();
		}

		function(cnt + 1);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = copyboard[i][j];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	function(0);

	cout << maxnum << "\n";

	return 0;
}