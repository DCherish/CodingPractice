#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int x;
	int y;
	int shape;
	bool exist;
};

int N;

bool pole[110][110];
bool bo[110][110];

vector<info> vec;

bool cmp(vector<int> &a, vector<int> &b)
{
	if (a[0] == b[0])
	{
		if (a[1] == b[1])
		{
			return a[2] < b[2];
		}
		else return a[1] < b[1];
	}
	else return a[0] < b[0];
}

bool check_install_bo(int x, int y)
{
    if (pole[x + 1][y] || pole[x + 1][y + 1]) return true;
    if (bo[x][y - 1] && bo[x][y + 1]) return true;
    
    return false;
}

bool check_install_pole(int x, int y)
{
    if (x == N) return true;
    
    if (bo[x][y - 1] || bo[x][y]) return true;
    if (pole[x + 1][y]) return true;
    
    return false;
}

void check_delete_bo(int x, int y)
{
	int idx = 0;
	bo[x][y] = false;

	for (int i = 0; i < vec.size(); i++)
	{
		int ix = vec[i].x;
		int iy = vec[i].y;
		int ishape = vec[i].shape;
        int iexist = vec[i].exist;
        
        if (!iexist) continue;

		if (x == ix && y == iy && ishape == 1)
		{
			idx = i;
			continue;
		}

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

	vec[idx].exist = false;
}

void check_delete_pole(int x, int y)
{
	int idx = 0;
	pole[x][y] = false;

	for (int i = 0; i < vec.size(); i++)
	{
		int ix = vec[i].x;
		int iy = vec[i].y;
		int ishape = vec[i].shape;
        int iexist = vec[i].exist;
        
        if (!iexist) continue;

		if (x == ix && y == iy && ishape == 0)
		{
			idx = i;
            continue;
		}

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

	vec[idx].exist = false;
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

		x = N - x;

		if (install == 1)
		{
			if (shape == 0)
			{
				if (check_install_pole(x, y))
				{
					pole[x][y] = true;
					vec.push_back({ x, y, shape, true });
				}
			}

			if (shape == 1)
			{
				if (check_install_bo(x, y))
				{
					bo[x][y] = true;
					vec.push_back({ x, y, shape, true });
				}
			}
		}
		else
		{
			if (shape == 0) check_delete_pole(x, y);
			if (shape == 1) check_delete_bo(x, y);
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (!vec[i].exist) continue;
        
		answer.push_back({ vec[i].y, N - vec[i].x, vec[i].shape });
	}

	sort(answer.begin(), answer.end(), cmp);

	return answer;
}