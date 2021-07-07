#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct pnt
{
	int x;
	int y;
};

struct block
{
	int sz;
	int r_cnt;
	int x;
	int y;
	vector<pnt> b_pos;
};

int N, M, ans;
int MAP[20][20];
bool visited[20][20];
bool r_visited[20][20];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(pnt a, pnt b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else return a.x < b.x;
}

block BFS(int x, int y, int idx)
{
	memset(r_visited, false, sizeof(r_visited));

	vector<pnt> blk;
	vector<pnt> except_r_blk;
	queue<pnt> Q;

	blk.push_back({ x, y });
	except_r_blk.push_back({ x, y });
	Q.push({ x, y });
	visited[x][y] = true;

	int rainbow = 0;

	while (!Q.empty())
	{
		int qx = Q.front().x;
		int qy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = qx + dx[i];
			int ny = qy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (MAP[nx][ny] == 0)
			{
				if (r_visited[nx][ny] == false)
				{
					r_visited[nx][ny] = true;
					rainbow++;
					blk.push_back({ nx, ny });
					Q.push({ nx, ny });
				}
			}
			else if (MAP[nx][ny] == idx)
			{
				if (visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					blk.push_back({ nx, ny });
					Q.push({ nx, ny });
					except_r_blk.push_back({ nx, ny });
				}
			}
		}
	}

	sort(except_r_blk.begin(), except_r_blk.end(), cmp);

	block result_block;
	result_block.sz = blk.size();
	result_block.r_cnt = rainbow;
	result_block.x = except_r_blk[0].x;
	result_block.y = except_r_blk[0].y;
	result_block.b_pos = blk;

	return result_block;
}

bool cmp_block(block a, block b)
{
	if (a.sz <= b.sz)
	{
		if (a.sz == b.sz)
		{
			if (a.r_cnt <= b.r_cnt)
			{
				if (a.r_cnt == b.r_cnt)
				{
					if (a.x <= b.x)
					{
						if (a.x == b.x)
						{
							if (a.y > b.y) return true;
							else return false;
						}
						else return false;
					}
					else return true;
				}
				else return false;
			}
			else return true;
		}
		else return false;
	}
	else return true;
}

block find_biggest_block()
{
	memset(visited, false, sizeof(visited));

	block result;
	result.sz = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == true) continue;
			if (MAP[i][j] == -1 || MAP[i][j] == -2 || MAP[i][j] == 0) continue;

			block temp_result = BFS(i, j, MAP[i][j]);

			if (result.sz == -1) result = temp_result;
			else
			{
				if (cmp_block(temp_result, result) == true) result = temp_result;
			}
		}
	}

	return result;
}

void do_gravity()
{
	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] == -1 || MAP[i][j] == -2) continue;

			int idx = MAP[i][j];
			int nx = i + 1;

			while (true)
			{
				if (MAP[nx][j] != -2) break;
				if (nx == N) break;
				nx++;
			}
			nx--;
			MAP[i][j] = -2;
			MAP[nx][j] = idx;
		}
	}
}

void do_rotate()
{
	vector<int> temp[20];

	int temp_idx = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			temp[temp_idx].push_back(MAP[j][i]);
		}
		temp_idx++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = temp[i][j];
		}
	}
}

void delete_block(block result)
{
	for (int i = 0; i < result.b_pos.size(); i++)
	{
		int x = result.b_pos[i].x;
		int y = result.b_pos[i].y;
		MAP[x][y] = -2;
	}

	ans += (result.b_pos.size() * result.b_pos.size());
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

	while (true)
	{
		block result = find_biggest_block();
		if (result.sz < 2) break;
		delete_block(result);
		do_gravity();
		do_rotate();
		do_gravity();
	}

	cout << ans << "\n";

	return 0;
}