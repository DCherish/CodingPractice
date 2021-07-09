#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N, M, d, s;
int MAP[50][50];

int score = 0;

vector<pnt> cmd;

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int dirx[4] = { 0, 1, 0, -1 };
int diry[4] = { -1, 0, 1, 0 };

void do_magic(int idx)
{
	int dir = cmd[idx].x;
	int speed = cmd[idx].y;

	int mid = N / 2;

	int x = mid;
	int y = mid;

	for (int i = 0; i < speed; i++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		MAP[nx][ny] = 0;

		x = nx;
		y = ny;
	}
}

void do_move()
{
	vector<int> temp;

	int mid = N / 2;
	bool state = false;

	int cx = mid;
	int cy = mid;

	int idx = 1;
	int t_idx = 1;
	int dir = 0;

	while (true)
	{
		if (idx == N)
		{
			idx -= 1;
			state = true;
		}

		for (int i = 0; i < idx; i++)
		{
			int nx = cx + dirx[dir];
			int ny = cy + diry[dir];

			cx = nx;
			cy = ny;

			if (MAP[nx][ny] == 0) continue;

			temp.push_back(MAP[nx][ny]);
		}

		if (state == true) break;

		if (t_idx == 1) t_idx++;
		else
		{
			idx++;
			t_idx = 1;
		}

		dir++;

		if (dir == 4) dir = 0;
	}

	memset(MAP, 0, sizeof(MAP));

	state = false;

	cx = mid;
	cy = mid;

	idx = 1;
	t_idx = 1;
	dir = 0;

	int tempidx = 0;

	while (temp.size() != 0)
	{
		if (idx == N)
		{
			idx -= 1;
			state = true;
		}

		for (int i = 0; i < idx; i++)
		{
			int nx = cx + dirx[dir];
			int ny = cy + diry[dir];

			cx = nx;
			cy = ny;

			MAP[nx][ny] = temp[tempidx];

			tempidx++;

			if (tempidx == temp.size())
			{
				state = true;
				break;
			}
		}

		if (state == true) break;

		if (t_idx == 1) t_idx++;
		else
		{
			idx++;
			t_idx = 1;
		}

		dir++;

		if (dir == 4) dir = 0;
	}
}

void do_explode()
{
	vector<pnt> expnt;
	bool e_state = false;

	int mid = N / 2;
	bool state = false;

	int cx = mid;
	int cy = mid;

	int idx = 1;
	int t_idx = 1;
	int dir = 0;

	int prev = -1;

	while (true)
	{
		if (idx == N)
		{
			idx -= 1;
			state = true;
		}

		for (int i = 0; i < idx; i++)
		{
			int nx = cx + dirx[dir];
			int ny = cy + diry[dir];

			cx = nx;
			cy = ny;

			if (prev == -1)
			{
				if (MAP[nx][ny] == 0)
				{
					state = true;
					break;
				}

				prev = MAP[nx][ny];
				expnt.push_back({ nx, ny });
			}
			else
			{
				if (prev == MAP[nx][ny])
				{
					expnt.push_back({ nx, ny });
				}
				else
				{
					if (expnt.size() >= 4)
					{
						e_state = true;

						for (int j = 0; j < expnt.size(); j++)
						{
							int ex = expnt[j].x;
							int ey = expnt[j].y;

							MAP[ex][ey] = 0;
						}

						score += prev * expnt.size();
					}

					expnt.clear();

					if (MAP[nx][ny] == 0)
					{
						state = true;
						break;
					}

					prev = MAP[nx][ny];
					expnt.push_back({ nx, ny });
				}
			}
		}

		if (state == true) break;

		if (t_idx == 1) t_idx++;
		else
		{
			idx++;
			t_idx = 1;
		}

		dir++;

		if (dir == 4) dir = 0;
	}

	if (e_state == true)
	{
		do_move();
		do_explode();
	}
}

void do_change()
{
	vector<int> temp;

	int mid = N / 2;
	bool state = false;

	int cx = mid;
	int cy = mid;

	int idx = 1;
	int t_idx = 1;
	int dir = 0;

	int prev = -1;
	int cnt = 0;

	while (true)
	{
		if (idx == N)
		{
			idx -= 1;
			state = true;
		}

		for (int i = 0; i < idx; i++)
		{
			int nx = cx + dirx[dir];
			int ny = cy + diry[dir];

			cx = nx;
			cy = ny;

			if (prev == -1)
			{
				prev = MAP[nx][ny];
				cnt++;
			}
			else if (prev == 0)
			{
				state = true;
				break;
			}
			else
			{
				if (prev == MAP[nx][ny])
				{
					cnt++;
				}
				else
				{
					temp.push_back(cnt);
					temp.push_back(prev);

					prev = MAP[nx][ny];
					cnt = 1;
				}
			}
		}

		if (state == true) break;

		if (t_idx == 1) t_idx++;
		else
		{
			idx++;
			t_idx = 1;
		}

		dir++;

		if (dir == 4) dir = 0;
	}

	memset(MAP, 0, sizeof(MAP));

	state = false;

	cx = mid;
	cy = mid;

	idx = 1;
	t_idx = 1;
	dir = 0;

	int tempidx = 0;

	while (temp.size() != 0)
	{
		if (idx == N)
		{
			idx -= 1;
			state = true;
		}

		for (int i = 0; i < idx; i++)
		{
			int nx = cx + dirx[dir];
			int ny = cy + diry[dir];

			cx = nx;
			cy = ny;

			MAP[nx][ny] = temp[tempidx];

			tempidx++;

			if (tempidx == temp.size())
			{
				state = true;
				break;
			}
		}

		if (state == true) break;

		if (t_idx == 1) t_idx++;
		else
		{
			idx++;
			t_idx = 1;
		}

		dir++;

		if (dir == 4) dir = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> d >> s;
		cmd.push_back({ d, s });
	}

	for (int i = 0; i < M; i++)
	{
		do_magic(i);
		do_move();
		do_explode();
		do_change();
	}

	cout << score << "\n";

	return 0;
}