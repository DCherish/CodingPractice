#include <iostream>
#include <queue>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N;

char arr[100][100];
bool visited[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int cnt_rgb = 0;
int cnt_cw_rgb = 0;

queue<pnt> Q;

void BFS(int x, int y, int idx)
{
	bool state = true;

	pnt p;
	p.x = x;
	p.y = y;

	visited[x][y] = true;

	if (idx == 0)
	{
		cnt_rgb++;
	}
	else
	{
		cnt_cw_rgb++;

		if (arr[x][y] != 'B') state = false;
	}

	Q.push(p);

	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;

			if (state == false)
			{
				if (arr[nx][ny] == 'B') continue;

				visited[nx][ny] = true;

				pnt np;
				np.x = nx;
				np.y = ny;

				Q.push(np);
			}
			else if (arr[cx][cy] != arr[nx][ny]) continue;
			else
			{
				visited[nx][ny] = true;

				pnt np;
				np.x = nx;
				np.y = ny;

				Q.push(np);
			}
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
			cin >> arr[i][j];

			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				BFS(i, j, 0);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				BFS(i, j, 1);
			}
		}
	}

	cout << cnt_rgb << " " << cnt_cw_rgb << "\n";

	return 0;
}