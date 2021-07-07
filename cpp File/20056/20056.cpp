#include <iostream>
#include <vector>

using namespace std;

struct FIREBALL
{
	int mass;
	int dir;
	int speed;
	int x;
	int y;
};

int N, M, K, ans;
int r, c, m, s, d;

vector<FIREBALL> MAP[50][50];
vector<FIREBALL> fireball;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int e_dir[4] = { 0, 2, 4, 6 };
int o_dir[4] = { 1, 3, 5, 7 };

void do_move()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAP[i][j].clear();
		}
	}

	for (int i = 0; i < fireball.size(); i++)
	{
		int mass = fireball[i].mass;
		int dir = fireball[i].dir;
		int speed = fireball[i].speed;
		int x = fireball[i].x;
		int y = fireball[i].y;

		int move = speed % N;

		int nx = x + move * dx[dir];
		int ny = y + move * dy[dir];

		if (nx < 0) nx += N;
		else if (nx >= N) nx -= N;

		if (ny < 0) ny += N;
		else if (ny >= N) ny -= N;

		MAP[nx][ny].push_back({ mass, dir, speed, nx, ny });
		fireball[i].x = nx;
		fireball[i].y = ny;
	}
}

void do_action()
{
	vector<FIREBALL> temp;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j].size() == 0) continue;

			if (MAP[i][j].size() == 1)
			{
				temp.push_back(MAP[i][j][0]);
				continue;
			}

			int mass_total = 0;
			int speed_total = 0;
			int cnt = MAP[i][j].size();

			bool e_state = true;
			bool o_state = true;

			for (int k = 0; k < cnt; k++)
			{
				mass_total += MAP[i][j][k].mass;
				speed_total += MAP[i][j][k].speed;

				if (MAP[i][j][k].dir % 2 == 0) o_state = false;
				else e_state = false;
			}

			int mass_final = mass_total / 5;
			int speed_final = speed_total / cnt;

			if (mass_final == 0) continue;

			if (e_state == true || o_state == true)
			{
				for (int k = 0; k < 4; k++)
				{
					temp.push_back({ mass_final, e_dir[k], speed_final, i, j });
				}
			}
			else
			{
				for (int k = 0; k < 4; k++)
				{
					temp.push_back({ mass_final, o_dir[k], speed_final, i, j });
				}
			}
		}
	}

	fireball = temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= M; i++)
	{
		cin >> r >> c >> m >> s >> d;

		r--;
		c--;

		MAP[r][c].push_back({ m, d, s, r, c });
		fireball.push_back({ m, d, s, r, c });
	}

	for (int i = 0; i < K; i++)
	{
		do_move();
		do_action();
	}

	for (int i = 0; i < fireball.size(); i++)
	{
		ans += fireball[i].mass;
	}

	cout << ans << "\n";

	return 0;
}