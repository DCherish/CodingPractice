#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int x;
	int y;
	int shape;
	int exist;
};

int N;
int pole[110][110];
int bo[110][110];

vector<info> info_vec;

bool check_install_pole(int x, int y)
{
	if (x == N) return true;
	if (y - 1 >= 0 && bo[x][y - 1] == true) return true;
	if (bo[x][y] == true) return true;
	if (pole[x + 1][y] == true) return true;

	return false;
}

bool check_install_bo(int x, int y)
{
	if (pole[x + 1][y] == true) return true;
	if (y + 1 <= N && pole[x + 1][y + 1] == true) return true;
	if (bo[x][y - 1] == true && bo[x][y + 1] == true) return true;

	return false;
}

void check_delete_pole(int x, int y)
{
	int idx = 0;
	pole[x][y] = false;

	for (int i = 0; i < info_vec.size(); i++)
	{
		int ix = info_vec[i].x;
		int iy = info_vec[i].y;
		int ishape = info_vec[i].shape;

		if (x == ix && y == iy && ishape == 0)
		{
			idx = i;
			continue;
		}

		if (info_vec[i].exist == -1) continue;

		if (ishape == 0 && check_install_pole(ix, iy) == false)
		{
			pole[x][y] = true;
			return;
		}

		if (ishape == 1 && check_install_bo(ix, iy) == false)
		{
			pole[x][y] = true;
			return;
		}
	}

	info_vec[idx].exist = -1;
}

void check_delete_bo(int x, int y)
{
	int idx = 0;
	bo[x][y] = false;

	for (int i = 0; i < info_vec.size(); i++)
	{
		int ix = info_vec[i].x;
		int iy = info_vec[i].y;
		int ishape = info_vec[i].shape;

		if (x == ix && y == iy && ishape == 1)
		{
			idx = i;
			continue;
		}

		if (info_vec[i].exist == -1) continue;

		if (ishape == 0 && check_install_pole(ix, iy) == false)
		{
			bo[x][y] = true;
			return;
		}

		if (ishape == 1 && check_install_bo(ix, iy) == false)
		{
			bo[x][y] = true;
			return;
		}
	}

	info_vec[idx].exist = -1;
}

bool cmp(info a, info b)
{
	if (a.exist == b.exist)
	{
		if (a.y == b.y)
		{
			if (a.x == b.x)
			{
				return a.shape < b.shape;
			}
			else return a.x >= b.x;
		}
		else return a.y <= b.y;
	}
	else return a.exist >= b.exist;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
	vector<vector<int>> answer;

	N = n;

	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][1];
		int y = build_frame[i][0];
		int shape = build_frame[i][2];
		int install = build_frame[i][3];

		x = n - x;

		if (install == 1)
		{
			if (shape == 0 && check_install_pole(x, y) == true)
			{
				info_vec.push_back({ x, y, shape, 1 });
				pole[x][y] = 1;
			}

			if (shape == 1 && check_install_bo(x, y) == true)
			{
				info_vec.push_back({ x, y, shape, 1 });
				bo[x][y] = 1;
			}
		}
		else
		{
			if (shape == 0) check_delete_pole(x, y);
			if (shape == 1) check_delete_bo(x, y);
		}
	}

	sort(info_vec.begin(), info_vec.end(), cmp);

	for (int i = 0; i < info_vec.size(); i++)
	{
		if (info_vec[i].exist == -1) break;
		answer.push_back({ info_vec[i].y, N - info_vec[i].x, info_vec[i].shape });
	}

	return answer;
}