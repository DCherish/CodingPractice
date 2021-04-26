#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];
int N, x, y, d, g, cnt;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

vector<int> Dir_info;

void Count_Square()
{
	cnt = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (arr[i][j] == 1 && arr[i + 1][j] == 1
				&& arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1)
			{
				cnt++;
			}
		}
	}
}

void Make_DC()
{
	int S = Dir_info.size();

	for (int i = S - 1; i >= 0; i--)
	{
		int nD = (Dir_info[i] + 1) % 4;

		x = x + dx[nD];
		y = y + dy[nD];

		arr[x][y] = 1;

		Dir_info.push_back(nD);
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
		cin >> y >> x >> d >> g;

		Dir_info.clear();

		arr[x][y] = 1;

		x = x + dx[d];
		y = y + dy[d];

		arr[x][y] = 1;


		Dir_info.push_back(d);

		for (int j = 0; j < g; j++)
		{
			Make_DC();
		}
	}

	Count_Square();

	cout << cnt << "\n";

	return 0;
}