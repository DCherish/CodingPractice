#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int arr[1000][1000];
int cnt[1000][1000];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 좌측 상단 -> 우측 하단 오른쪽 순
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char c;
int H, W, result;
bool visited[1000][1000];

queue<pnt> Q;
vector<pnt> vec;

void BFS()
{
	result = 0;

	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
			if (visited[nx][ny] == true) continue;
			if (arr[nx][ny] != 0) cnt[nx][ny] += 1;

			if (cnt[nx][ny] >= arr[nx][ny])
			{
				vec.push_back({ nx, ny });
				visited[nx][ny] = true;
			}
		}

		if (Q.empty() && vec.size() != 0)
		{
			result += 1;

			for (int i = 0; i < vec.size(); i++)
			{
				Q.push({ vec[i].x, vec[i].y });
			}

			vec.clear();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> c;

			if (c == '.')
			{
				Q.push({ i, j });
				arr[i][j] = 0;
				visited[i][j] = true;
			}
			else
			{
				arr[i][j] = (int)c - (int)'0';
			}
		}
	}

	BFS();

	cout << result << "\n";

	return 0;
}