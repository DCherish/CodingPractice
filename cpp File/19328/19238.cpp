#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class pnt
{
public:
	int x;
	int y;
	int gas;
};

class passenger
{
public:
	int px;
	int py;
	int gx;
	int gy;
};

class cmp
{
public:
	bool operator()(pnt p1, pnt p2)
	{
		if (p1.gas != p2.gas) return p1.gas < p2.gas;

		if (p1.x != p2.x) return p1.x > p2.x;
		return p1.y > p2.y;
	}
};

int N, M, G;

int tx, ty;

int pcount;

int resultgas;
int answer;

bool visitmap[21][21];
int map[21][21];

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

vector<pnt> pv;
passenger psg[401];

bool cmpare(pnt p1, pnt p2)
{
	if (p1.gas != p2.gas) return p1.gas > p2.gas;

	if (p1.x != p2.x) return p1.x < p2.x;
	return p1.y < p2.y;
}

void Resetmap()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == -1)
			{
				visitmap[i][j] = true;
			}
			else
			{
				visitmap[i][j] = false;
			}
		}
	}
}

void Checkmap()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] != 0 && map[i][j] != -1)
			{
				answer = -1;
				return;
			}
		}
	}
}

void DestinationBFS(int nx, int ny, int cgas)
{
	priority_queue<pnt, vector<pnt>, cmp> DPQ;
	pnt dp;

	int index;
	index = map[nx][ny];

	dp.x = nx;
	dp.y = ny;
	dp.gas = cgas;

	DPQ.push(dp);

	Resetmap();

	map[nx][ny] = 0;
	visitmap[nx][ny] = true;

	while (!DPQ.empty())
	{
		int cx = DPQ.top().x;
		int cy = DPQ.top().y;
		int cgas = DPQ.top().gas;

		DPQ.pop();

		if (cgas == 0)
		{
			resultgas = -1;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int dnx = cx + dx[i];
			int dny = cy + dy[i];

			if (dnx < 1 || dny < 1 || dnx > N || dny > N) continue;
			if (visitmap[dnx][dny] == true) continue;

			if (psg[index].gx == dnx && psg[index].gy == dny)
			{
				tx = dnx;
				ty = dny;
				resultgas = cgas - 1;

				while (!DPQ.empty()) DPQ.pop();

				return;
			}
			else
			{
				pnt np;

				np.x = dnx;
				np.y = dny;
				np.gas = cgas - 1;

				DPQ.push(np);

				visitmap[dnx][dny] = true;
			}
		}
	}

	resultgas = -1;
}

void BFS()
{
	for (int r = 0; r < M; r++)
	{
		priority_queue<pnt, vector<pnt>, cmp> PQ;
		pnt p;

		p.x = tx;
		p.y = ty;
		p.gas = G;

		visitmap[tx][ty] = true;

		if (map[tx][ty] != 0)
		{
			DestinationBFS(tx, ty, G);

			if (resultgas == -1)
			{
				answer = -1;
				return;
			}
			else
			{
				answer = resultgas + (G - resultgas) * 2;
				pcount = pcount - 1;
			}

			if (pcount == 0) return;

			G = answer;
			Resetmap();
			continue;
		}

		PQ.push(p);

		while (!PQ.empty())
		{
			int cx = PQ.top().x;
			int cy = PQ.top().y;
			int cgas = PQ.top().gas;

			PQ.pop();

			if (map[cx][cy] != 0)
			{
				DestinationBFS(cx, cy, cgas);

				if (resultgas == -1)
				{
					answer = -1;
					return;
				}
				else
				{
					answer = resultgas + (cgas - resultgas) * 2;
					pcount = pcount - 1;

					if (pcount == 0)
					{
						return;
					}
				}

				while (!PQ.empty()) PQ.pop();
				G = answer;
				Resetmap();
				break;
			}

			if (cgas == 0) continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
				if (visitmap[nx][ny] == true) continue;

				pnt np;

				np.x = nx;
				np.y = ny;
				np.gas = cgas - 1;

				PQ.push(np);

				visitmap[nx][ny] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> G;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int info;
			cin >> info;

			if (info == 1)
			{
				map[i][j] = -1;
				visitmap[i][j] = true;
			}
			else
			{
				map[i][j] = 0;
				visitmap[i][j] = false;
			}
		}
	}

	cin >> tx >> ty;

	for (int i = 1; i <= M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		psg[i] = { a, b, c, d };

		map[a][b] = i;
	}

	pcount = M;

	BFS();
	Checkmap();

	cout << answer << "\n";

	return 0;
}