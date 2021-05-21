#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct pnt
{
	int x;
	int y;
	int cost;
};

int N;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int fish[20][20];
bool visited[20][20];

int s_x, s_y;
int s_size = 2;
int s_cnt = 2;
int result = 0;

bool state = true;

queue<pnt> Q;
vector<pnt> vec;

bool cmp(pnt a, pnt b)
{
	if (a.cost == b.cost)
	{
		if (a.x == b.x)
		{
			return a.y < b.y;
		}
		else return a.x < b.x;
	}
	else return a.cost < b.cost;
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
		}
	}

	while (!Q.empty())
	{
		Q.pop();
	}

	vec.clear();
}

void BFS()
{
	visited[s_x][s_y] = true;
	Q.push({ s_x, s_y, 0 });

	while (!Q.empty())
	{
		int x = Q.front().x;
		int y = Q.front().y;
		int cost = Q.front().cost;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] == true) continue;

			if (fish[nx][ny] == 0 || fish[nx][ny] == s_size)
			{
				visited[nx][ny] = true;
				Q.push({ nx, ny, cost + 1 });
			}
			else if (fish[nx][ny] < s_size)
			{
				visited[nx][ny] = true;
				Q.push({ nx, ny, cost + 1 });
				vec.push_back({ nx, ny, cost + 1 });
			}
		}
	}

	if (vec.size() == 0)
	{
		state = false;
	}
	else if (vec.size() == 1)
	{
		fish[vec[0].x][vec[0].y] = 9;
		fish[s_x][s_y] = 0;
		s_x = vec[0].x;
		s_y = vec[0].y;
		s_cnt--;
		result += vec[0].cost;

		if (s_cnt == 0)
		{
			s_size++;
			s_cnt = s_size;
		}
	}
	else
	{
		sort(vec.begin(), vec.end(), cmp);

		fish[vec[0].x][vec[0].y] = 9;
		fish[s_x][s_y] = 0;
		s_x = vec[0].x;
		s_y = vec[0].y;
		s_cnt--;
		result += vec[0].cost;

		if (s_cnt == 0)
		{
			s_size++;
			s_cnt = s_size;
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
			cin >> fish[i][j];

			if (fish[i][j] == 9)
			{
				s_x = i;
				s_y = j;
			}
		}
	}

	while (state)
	{
		BFS();

		init();
	}

	cout << result << "\n";

	return 0;
}