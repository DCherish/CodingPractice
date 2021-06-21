#include <iostream>
#include <vector>

using namespace std;

struct CHESS
{
	int x;
	int y;
	int dir;
};

int N, K, ans;
int MAP[12][12];
vector<int> MAP_State[12][12];
CHESS chess[10];

bool state = false;
int cnt = 1;

int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int Find_Delete_Num(int x, int y, int idx)
{
	/* 해당 말을 옮긴 후, 기존 좌표에서 몇 번 삭제를 해야 하는지 찾는 함수. */
	int temp = 0;

	for (int i = MAP_State[x][y].size() - 1; i >= 0; i--)
	{
		if (MAP_State[x][y][i] == idx) break;
		temp++;
	}

	return temp + 1;
}

int Reverse_Dir(int idx)
{
	int og_dir = chess[idx].dir;

	if (og_dir == 1) return 2;
	else if (og_dir == 2) return 1;
	else if (og_dir == 3) return 4;
	else if (og_dir == 4) return 3;
}

void Movechess(int x, int y, int nx, int ny, int idx, int pos, int MS)
{
	if (MS == 0)
	{
		for (int i = pos; i < MAP_State[x][y].size(); i++)
		{
			MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
			int Idx = MAP_State[x][y][i];
			chess[Idx].x = nx;
			chess[Idx].y = ny;
		}

		int rm_num = Find_Delete_Num(x, y, idx);

		for (int i = 0; i < rm_num; i++) MAP_State[x][y].pop_back();
	}
	else if (MS == 1)
	{
		for (int i = MAP_State[x][y].size() - 1; i >= pos; i--)
		{
			MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
			int Idx = MAP_State[x][y][i];
			chess[Idx].x = nx;
			chess[Idx].y = ny;
		}

		int rm_num = Find_Delete_Num(x, y, idx);

		for (int i = 0; i < rm_num; i++) MAP_State[x][y].pop_back();
	}
	else if (MS == 2)
	{
		int rv_dir = Reverse_Dir(idx);
		chess[idx].dir = rv_dir;

		int nnx = x + dx[rv_dir];
		int nny = y + dy[rv_dir];

		if (nnx >= 0 && nny >= 0 && nnx < N && nny < N)
		{
			if (MAP[nnx][nny] != 2) Movechess(x, y, nnx, nny, idx, pos, MAP[nnx][nny]);
		}
	}
}

int Find_Position(int x, int y, int Idx)
{
	/* 해당 말이 몇 번째에 위치하고 있는지 찾아서 return 하는 함수. */
	for (int i = 0; i < MAP_State[x][y].size(); i++)
	{
		if (MAP_State[x][y][i] == Idx) return i;
	}
}

bool Check_State()
{
	for (int i = 0; i < K; i++)
	{
		int x = chess[i].x;
		int y = chess[i].y;

		if (MAP_State[x][y].size() >= 4) return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int x, y, d;

		cin >> x >> y >> d;
		x--;
		y--;

		chess[i].x = x;
		chess[i].y = y;
		chess[i].dir = d;

		MAP_State[x][y].push_back(i);
	}

	while (true)
	{
		if (cnt > 1000) break;

		for (int i = 0; i < K; i++)
		{
			int x = chess[i].x;
			int y = chess[i].y;
			int dir = chess[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			int Pos = Find_Position(x, y, i);
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) Movechess(x, y, nx, ny, i, Pos, MAP[nx][ny]);
			else Movechess(x, y, nx, ny, i, Pos, 2);

			if (Check_State() == true)
			{
				state = true;
				ans = cnt;
				break;
			}
		}

		if (state == true) break;
		cnt++;
	}

	if (state == false)
	{
		ans = -1;
	}

	cout << ans << "\n";

	return 0;
}