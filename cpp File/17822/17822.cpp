#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct dot
{
	int first;
	int second;
};

struct info
{
	int num;
	int dir;
	int k;
};

int N, M, T, num, ans;
int circle[51][51];
int copy_circle[51][51];
bool visited[51][51];

vector<info> cmd;

void turning_circle(int idx, int dir, int k)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copy_circle[i][j] = circle[i][j];
		}
	}

	if (dir == 0)
	{
		for (int i = 0; i < M; i++)
		{
			int value = circle[idx][i];
			int pos = (i + k) % M;
			copy_circle[idx][pos] = value;
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			int value = circle[idx][i];
			int temp_k = k % M;
			int pos = i - temp_k;
			if (pos < 0) pos = pos + M;
			copy_circle[idx][pos] = value;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			circle[i][j] = copy_circle[i][j];
		}
	}
}

bool BFS(int x, int y)
{
	queue<dot> Q;
	vector<dot> V;

	Q.push({ x, y });
	V.push_back({ x, y });

	visited[x][y] = true;

	while (!Q.empty())
	{
		int c_num = Q.front().first;
		int idx = Q.front().second;
		Q.pop();

		int left_idx = idx - 1;
		int right_idx = idx + 1;
		int left_circle = c_num - 1;
		int right_circle = c_num + 1;

		if (left_idx < 0) left_idx = M - 1;
		if (right_idx >= M) right_idx = right_idx % M;

		if (circle[c_num][idx] == circle[c_num][left_idx])
		{
			if (visited[c_num][left_idx] == false)
			{
				visited[c_num][left_idx] = true;
				Q.push({ c_num, left_idx });
				V.push_back({ c_num, left_idx });
			}
		}

		if (circle[c_num][idx] == circle[c_num][right_idx])
		{
			if (visited[c_num][right_idx] == false)
			{
				visited[c_num][right_idx] = true;
				Q.push({ c_num, right_idx });
				V.push_back({ c_num, right_idx });
			}
		}

		if (left_circle > 0)
		{
			if (circle[c_num][idx] == circle[left_circle][idx])
			{
				if (visited[left_circle][idx] == false)
				{
					visited[left_circle][idx] = true;
					Q.push({ left_circle, idx });
					V.push_back({ left_circle, idx });
				}
			}
		}

		if (right_circle <= N)
		{
			if (circle[c_num][idx] == circle[right_circle][idx])
			{
				if (visited[right_circle][idx] == false)
				{
					visited[right_circle][idx] = true;
					Q.push({ right_circle, idx });
					V.push_back({ right_circle, idx });
				}
			}
		}
	}

	if (V.size() == 1)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < V.size(); i++)
		{
			int xx = V[i].first;
			int yy = V[i].second;
			circle[xx][yy] = 0;
		}
		return true;
	}
}

bool check_adjacency()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = false;
		}
	}

	bool flag = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == false && circle[i][j] != 0)
			{
				bool T = BFS(i, j);
				if (T == true) flag = true;
			}
		}
	}

	return flag;
}

dot cal()
{
	dot R;

	R.first = 0;
	R.second = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			R.first += circle[i][j];

			if (circle[i][j] != 0) R.second++;
		}
	}

	return R;
}

void change_value(double avg)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (circle[i][j] == 0) continue;
			if ((double)(circle[i][j]) > avg) circle[i][j]--;
			else if ((double)(circle[i][j]) < avg) circle[i][j]++;
		}
	}
}

void solve()
{
	for (int i = 0; i < T; i++)
	{
		int num = cmd[i].num;
		int dir = cmd[i].dir;
		int k = cmd[i].k;

		for (int j = num; j <= N; j = j + num)
		{
			turning_circle(j, dir, k);
		}

		if (check_adjacency() == false)
		{
			dot temp = cal();

			double avg = (double)(temp.first) / (double)(temp.second);
			change_value(avg);
		}
	}

	ans = cal().first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> circle[i][j];
		}
	}

	for (int i = 0; i < T; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		cmd.push_back({ a, b, c });
	}

	solve();

	cout << ans << "\n";

	return 0;
}