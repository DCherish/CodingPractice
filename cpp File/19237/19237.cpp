#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SHARK
{
	int x;
	int y;
	int dir;
	bool alive;
	vector<int> priority[5];
};

struct MAP_INFO
{
	vector<int> vec;
	int smell_host;
	int smell_time;
};

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int N, M, k, s, d;
MAP_INFO MAP[20][20];
SHARK shark[401];

bool state = false;
int cnt = 0;
int ans;

bool check_shark()
{
	for (int i = 2; i <= M; i++)
	{
		if (shark[i].alive == true) return false;
	}

	return true;
}

void setting_smell()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j].smell_time == 0) continue;

			MAP[i][j].smell_time--;

			if (MAP[i][j].smell_time == 0)
			{
				MAP[i][j].smell_host = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (shark[i].alive == false) continue;

		int x = shark[i].x;
		int y = shark[i].y;
		MAP[x][y].smell_host = i;
		MAP[x][y].smell_time = k;
	}
}

void move_shark()
{
	for (int i = 1; i <= M; i++)
	{
		if (shark[i].alive == false) continue;

		int x = shark[i].x;
		int y = shark[i].y;

		MAP[x][y].vec.clear();
	}

	for (int i = 1; i <= M; i++)
	{
		if (shark[i].alive == false) continue;

		int x = shark[i].x;
		int y = shark[i].y;
		int dir = shark[i].dir;
		int temp_x, temp_y, temp_dir;

		temp_x = -1;
		temp_y = -1;
		temp_dir = -1;

		bool flag = false;

		for (int j = 0; j < shark[i].priority[dir].size(); j++)
		{
			int ndir = shark[i].priority[dir][j];

			int nx = x + dx[ndir];
			int ny = y + dy[ndir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

			if (MAP[nx][ny].smell_time == 0)
			{
				flag = true;
				MAP[nx][ny].vec.push_back(i);
				shark[i].x = nx;
				shark[i].y = ny;
				shark[i].dir = ndir;
				break;
			}
			else
			{
				if (MAP[nx][ny].smell_host == i)
				{
					if (temp_x == -1)
					{
						temp_x = nx;
						temp_y = ny;
						temp_dir = ndir;
					}
				}
			}
		}

		if (flag == false)
		{
			MAP[temp_x][temp_y].vec.push_back(i);
			shark[i].x = temp_x;
			shark[i].y = temp_y;
			shark[i].dir = temp_dir;
		}
	}
}

void resetting_smell()
{
}

void killing_shark()
{
	for (int i = 1; i <= M; i++)
	{
		if (shark[i].alive == false) continue;

		int x = shark[i].x;
		int y = shark[i].y;

		if (MAP[x][y].vec.size() >= 2)
		{
			sort(MAP[x][y].vec.begin(), MAP[x][y].vec.end());

			int first_shark_num = MAP[x][y].vec[0];

			for (int j = 1; j < MAP[x][y].vec.size(); j++)
			{
				int shark_num = MAP[x][y].vec[j];
				shark[shark_num].alive = false;
			}

			MAP[x][y].vec.clear();
			MAP[x][y].vec.push_back(first_shark_num);
			MAP[x][y].smell_host = first_shark_num;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> k;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> s;

			if (s != 0)
			{
				MAP[i][j].vec.push_back(s);
				shark[s].x = i;
				shark[s].y = j;
			}

			MAP[i][j].smell_host = 0;
			MAP[i][j].smell_time = 0;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> d;
		shark[i].dir = d;
		shark[i].alive = true;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cin >> d;
				shark[i].priority[j].push_back(d);
			}
		}
	}

	while (cnt <= 1000)
	{
		if (check_shark() == true)
		{
			ans = cnt;
			state = true;
			break;
		}

		setting_smell();
		move_shark();
		killing_shark();

		cnt++;
	}

	if (state == false)
	{
		ans = -1;
	}

	cout << ans << "\n";

	return 0;
}