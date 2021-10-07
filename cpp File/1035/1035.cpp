#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

struct pnt
{
	int x;
	int y;
};

vector<pnt> vec;
bool used[5][5], visited[5][5];
char MAP[5][5];

int mindist = 10000;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> MAP[i][j];

			if (MAP[i][j] == '*') vec.push_back({ i, j });
		}
	}
}

pnt findfirstpnt()
{
	pnt p;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (used[i][j])
			{
				p.x = i;
				p.y = j;

				return p;
			}
		}
	}
}

int count(pnt p)
{
	int x = p.x;
	int y = p.y;

	visited[x][y] = true;

	int cnt = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
		if (!used[nx][ny] || visited[nx][ny]) continue;

		pnt np;
		np.x = nx;
		np.y = ny;

		cnt += count(np);
	}

	return cnt;
}

bool check()
{
	memset(visited, false, sizeof(visited));

	if (count(findfirstpnt()) == vec.size()) return true;
	else return false;
}

void bruteForce(int n, int dist)
{
	if (dist >= mindist) return;

	if (n == vec.size())
	{
		if (check())
		{
			if (mindist > dist) mindist = dist;
		}

		return;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (used[i][j]) continue;

			used[i][j] = true;
			bruteForce(n + 1, dist + abs(i - vec[n].x) + abs(j - vec[n].y));
			used[i][j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	bruteForce(0, 0);

	cout << mindist << "\n";

	return 0;
}