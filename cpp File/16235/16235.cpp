#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, K, x, y, z, cnt;

int E[10][10];
int A[10][10];

vector<int> vec[10][10];

void solution()
{
	for (int i = 0; i < N; i++) // Spring And Summer
	{
		for (int j = 0; j < N; j++)
		{
			if (vec[i][j].size() == 0) continue;

			int die_age_sum = 0;

			vector<int> temp;

			sort(vec[i][j].begin(), vec[i][j].end());

			for (int k = 0; k < vec[i][j].size(); k++)
			{
				int age = vec[i][j][k];

				if (E[i][j] >= age)
				{
					E[i][j] -= age;
					temp.push_back(age + 1);
				}
				else
				{
					die_age_sum += age / 2;
				}
			}

			vec[i][j].clear();

			for (int k = 0; k < temp.size(); k++)
			{
				vec[i][j].push_back(temp[k]);
			}

			E[i][j] += die_age_sum;
		}
	}



	for (int i = 0; i < N; i++) // Summer
	{
		for (int j = 0; j < N; j++)
		{
			if (vec[i][j].size() == 0) continue;

			for (int k = 0; k < vec[i][j].size(); k++)
			{
				int age = vec[i][j][k];

				if (age % 5 == 0)
				{
					for (int p = 0; p < 8; p++)
					{
						int nx = i + dx[p];
						int ny = j + dy[p];

						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

						vec[nx][ny].push_back(1);
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) // Winter
	{
		for (int j = 0; j < N; j++)
		{
			E[i][j] += A[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];

			E[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;

		x--;
		y--;

		vec[x][y].push_back(z);
	}

	for (int i = 0; i < K; i++)
	{
		solution();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cnt += vec[i][j].size();
		}
	}

	cout << cnt << "\n";

	return 0;
}