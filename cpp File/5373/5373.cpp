#include <iostream>
#include <string>
#include <vector>

struct info
{
	char face; // 상 하 전 후 좌 우
	char wise; // 반시계 시계
};

using namespace std;

int T, n;
string how;

char cube[3][3][6]; // 흰 노 빨 오 초 파

vector<char> answer;

void do_rotate(int idx, int wise)
{
	vector<char> temp;

	if (wise == 1)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int i = 2; i >= 0; i--)
			{
				temp.push_back(cube[i][j][idx]);
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[i][j][idx] = temp[i * 3 + j];
			}
		}
	}
	else
	{
		for (int j = 2; j >= 0; j--)
		{
			for (int i = 0; i < 3; i++)
			{
				temp.push_back(cube[i][j][idx]);
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cube[i][j][idx] = temp[i * 3 + j];
			}
		}
	}
}

void solve(vector<info> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		char t_face = vec[i].face;
		char t_wise = vec[i].wise;

		if (t_face == 'U')
		{
			if (t_wise == '+')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[0][j][2]);
				}

				for (int j = 0; j < 3; j++) // ok
				{
					cube[0][j][2] = cube[0][j][5];
					cube[0][j][5] = cube[0][j][3];
					cube[0][j][3] = cube[0][j][4];
					cube[0][j][4] = temp[j];
				}

				do_rotate(0, 1);
			}
			else if (t_wise == '-')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[0][j][2]);
				}

				for (int j = 0; j < 3; j++) // ok
				{
					cube[0][j][2] = cube[0][j][4];
					cube[0][j][4] = cube[0][j][3];
					cube[0][j][3] = cube[0][j][5];
					cube[0][j][5] = temp[j];
				}

				do_rotate(0, 0);
			}
		}
		else if (t_face == 'D')
		{
			if (t_wise == '+')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[2][j][2]);
				}

				for (int j = 0; j < 3; j++) // ok
				{
					cube[2][j][2] = cube[2][j][4];
					cube[2][j][4] = cube[2][j][3];
					cube[2][j][3] = cube[2][j][5];
					cube[2][j][5] = temp[j];
				}

				do_rotate(1, 1);
			}
			else if (t_wise == '-')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[2][j][2]);
				}

				for (int j = 0; j < 3; j++) // ok
				{
					cube[2][j][2] = cube[2][j][5];
					cube[2][j][5] = cube[2][j][3];
					cube[2][j][3] = cube[2][j][4];
					cube[2][j][4] = temp[j];
				}

				do_rotate(1, 0);
			}
		}
		else if (t_face == 'F')
		{
			if (t_wise == '+')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[2][j][0]);
				}

				for (int j = 0; j < 3; j++) // ok
				{
					cube[2][j][0] = cube[2 - j][2][4];
					cube[2 - j][2][4] = cube[0][2 - j][1];
					cube[0][2 - j][1] = cube[j][0][5];
					cube[j][0][5] = temp[j];
				}

				do_rotate(2, 1);
			}
			else if (t_wise == '-')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[2][j][0]);
				}

				for (int j = 0; j < 3; j++) // ok
				{
					cube[2][j][0] = cube[j][0][5];
					cube[j][0][5] = cube[0][2 - j][1];
					cube[0][2 - j][1] = cube[2 - j][2][4];
					cube[2 - j][2][4] = temp[j];
				}

				do_rotate(2, 0);
			}
		}
		else if (t_face == 'B')
		{
			if (t_wise == '+')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[0][j][0]);
				}

				for (int j = 0; j < 3; j++)
				{
					cube[0][j][0] = cube[j][2][5];
					cube[j][2][5] = cube[2][2 - j][1];
					cube[2][2 - j][1] = cube[2 - j][0][4];
					cube[2 - j][0][4] = temp[j];
				}

				do_rotate(3, 1);
			}
			else if (t_wise == '-')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[0][j][0]);
				}

				for (int j = 0; j < 3; j++)
				{
					cube[0][j][0] = cube[2 - j][0][4];
					cube[2 - j][0][4] = cube[2][2 - j][1];
					cube[2][2 - j][1] = cube[j][2][5];
					cube[j][2][5] = temp[j];
				}

				do_rotate(3, 0);
			}
		}
		else if (t_face == 'L')
		{
			if (t_wise == '+')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[j][0][0]);
				}

				for (int j = 0; j < 3; j++)
				{
					cube[j][0][0] = cube[2 - j][2][3];
					cube[2 - j][2][3] = cube[j][0][1];
					cube[j][0][1] = cube[j][0][2];
					cube[j][0][2] = temp[j];
				}

				do_rotate(4, 1);
			}
			else if (t_wise == '-')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[j][0][0]);
				}

				for (int j = 0; j < 3; j++)
				{
					cube[j][0][0] = cube[j][0][2];
					cube[j][0][2] = cube[j][0][1];
					cube[j][0][1] = cube[2 - j][2][3];
					cube[2 - j][2][3] = temp[j];
				}

				do_rotate(4, 0);
			}
		}
		else if (t_face == 'R')
		{
			if (t_wise == '+')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[j][2][0]);
				}

				for (int j = 0; j < 3; j++)
				{
					cube[j][2][0] = cube[j][2][2];
					cube[j][2][2] = cube[j][2][1];
					cube[j][2][1] = cube[2 - j][0][3];
					cube[2 - j][0][3] = temp[j];
				}

				do_rotate(5, 1);
			}
			else if (t_wise == '-')
			{
				vector<char> temp;

				for (int j = 0; j < 3; j++)
				{
					temp.push_back(cube[j][2][0]);
				}

				for (int j = 0; j < 3; j++)
				{
					cube[j][2][0] = cube[2 - j][0][3];
					cube[2 - j][0][3] = cube[j][2][1];
					cube[j][2][1] = cube[j][2][2];
					cube[j][2][2] = temp[j];
				}

				do_rotate(5, 0);
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cube[i][j][0] = 'w';
			cube[i][j][1] = 'y';
			cube[i][j][2] = 'r';
			cube[i][j][3] = 'o';
			cube[i][j][4] = 'g';
			cube[i][j][5] = 'b';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		vector<info> vec;

		cin >> n;
		cin.ignore(256, '\n');

		getline(cin, how);

		for (int j = 0; j < n; j++)
		{
			vec.push_back({ how[j * 3], how[j * 3 + 1] });
		}

		init();

		solve(vec);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				answer.push_back(cube[i][j][0]);
			}
		}
	}

	for (int i = 1; i <= answer.size(); i++)
	{
		cout << answer[i - 1];

		if (i % 3 == 0) cout << "\n";
	}

	return 0;
}