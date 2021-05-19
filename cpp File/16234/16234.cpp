#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N, L, R;
int A[50][50];
bool visited[50][50];

int answer = 0;
bool state = true;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pnt> Q, Q_A;

bool calc(int xx, int yy, int x, int y)
{
	if (L <= abs(A[xx][yy] - A[x][y]) && abs(A[xx][yy] - A[x][y]) <= R) return true;
	else return false;
}

void BFS(int x, int y)
{
	visited[x][y] = true;

	int sum = 0;
	int cnt = 0;

	Q.push({ x, y });
	Q_A.push({ x, y });

	while (!Q.empty())
	{
		int qx = Q.front().x;
		int qy = Q.front().y;
		Q.pop();

		sum += A[qx][qy];
		cnt += 1;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] == true) continue;

			if (calc(nx, ny, x, y) == true)
			{
				visited[nx][ny] = true;
				Q.push({ nx, ny });
				Q_A.push({ nx, ny });
			}
		}
	}

	int value = sum / cnt;

	while (!Q_A.empty())
	{
		int cx = Q_A.front().x;
		int cy = Q_A.front().y;
		Q_A.pop();

		A[cx][cy] = value;
	}
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
}

bool any_loc(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

		if (L <= abs(A[nx][ny] - A[x][y]) && abs(A[nx][ny] - A[x][y]) <= R) return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	while (state)
	{
		state = false;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == false && any_loc(i, j) == true)
				{
					BFS(i, j);
					state = true;
				}
			}
		}

		if (state == true) answer++;

		init();
	}

	cout << answer << "\n";

	return 0;
}