#include <string>

using namespace std;

bool visited[11][11][11][11];

int x, y, idx;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int solution(string dirs)
{
	int answer = 0;

	x = 5;
	y = 5;

	for (int i = 0; i < dirs.length(); i++)
	{
		if (dirs[i] == 'U') idx = 0;
		else if (dirs[i] == 'D') idx = 1;
		else if (dirs[i] == 'L') idx = 2;
		else if (dirs[i] == 'R') idx = 3;

		int nx = x + dx[idx];
		int ny = y + dy[idx];

		if (nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue;

		if (visited[x][y][nx][ny] == false && visited[nx][ny][x][y] == false)
		{
			visited[x][y][nx][ny] = true;
			visited[nx][ny][x][y] = true;
			answer++;
		}

		x = nx;
		y = ny;
	}

	return answer;
}