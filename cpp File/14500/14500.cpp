#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[510][510];
bool visited[510][510];

int answer = 0;

int dx[4] = { -1, 1, 0, 0 }; // ╩С го аб ©Л
int dy[4] = { 0, 0, -1, 1 }; // ╩С го аб ©Л

int DFS(int x, int y, int depth)
{
	if (depth == 4) // 5
	{
		return arr[x][y];
	}

	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (visited[nx][ny] == true) continue;

		visited[nx][ny] = true;
		sum = max(sum, arr[x][y] + DFS(nx, ny, depth + 1));
		visited[nx][ny] = false;
	}

	return sum;
}

int spcCase(int x, int y)
{
	int sum = 0;

	if (x - 1 >= 0 && x + 1 < N && y + 1 < M) // ╓©
	{
		sum = max(sum, arr[x - 1][y] + arr[x][y] + arr[x + 1][y] + arr[x][y + 1]);
	}

	if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0) // ╓ц
	{
		sum = max(sum, arr[x - 1][y] + arr[x][y] + arr[x + 1][y] + arr[x][y - 1]);
	}

	if (y - 1 >= 0 && y + 1 < M && x - 1 >= 0) // ╓г
	{
		sum = max(sum, arr[x][y - 1] + arr[x][y] + arr[x][y + 1] + arr[x - 1][y]);
	}

	if (y - 1 >= 0 && y + 1 < M && x + 1 < N) // ╓л
	{
		sum = max(sum, arr[x][y - 1] + arr[x][y] + arr[x][y + 1] + arr[x + 1][y]);
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			answer = max(answer, DFS(i, j, 1));
			answer = max(answer, spcCase(i, j));
			visited[i][j] = false;
		}
	}

	cout << answer << "\n";

	return 0;
}