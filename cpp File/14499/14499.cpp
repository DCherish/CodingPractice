#include <iostream>
#include <vector>

using namespace std;

int N, M, x, y, K;
int result, num, d_temp;

vector<int> answer;

int arr[21][21];
int dice[4][3];

int nx, ny;

int dx[4] = { 0, 0, -1, 1 }; // µ¿ ¼­ ºÏ ³²
int dy[4] = { 1, -1, 0, 0 }; // µ¿ ¼­ ºÏ ³²

bool check(int temp)
{
	nx = x + dx[temp - 1];
	ny = y + dy[temp - 1];

	if (nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
	else return true;
}

void solve(int temp)
{
	if (check(temp) == false) return;

	if (temp == 1) // µ¿ roll
	{
		d_temp = dice[1][2];

		for (int i = 1; i >= 0; i--)
		{
			dice[1][i + 1] = dice[1][i];
		}

		dice[1][0] = dice[3][1];

		dice[3][1] = d_temp;
	}
	else if (temp == 2) // ¼­ roll
	{
		d_temp = dice[1][0];

		for (int i = 0; i < 2; i++)
		{
			dice[1][i] = dice[1][i + 1];
		}

		dice[1][2] = dice[3][1];

		dice[3][1] = d_temp;
	}
	else if (temp == 3) // ºÏ roll
	{
		d_temp = dice[0][1];

		for (int i = 0; i < 3; i++)
		{
			dice[i][1] = dice[i + 1][1];
		}

		dice[3][1] = d_temp;
	}
	else // ³² roll
	{
		d_temp = dice[3][1];

		for (int i = 2; i >= 0; i--)
		{
			dice[i + 1][1] = dice[i][1];
		}

		dice[0][1] = d_temp;
	}

	if (arr[nx][ny] == 0)
	{
		arr[nx][ny] = dice[3][1];
	}
	else
	{
		dice[3][1] = arr[nx][ny];
		arr[nx][ny] = 0;
	}

	x = nx;
	y = ny;

	answer.push_back(dice[1][1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> num;

		solve(num);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}