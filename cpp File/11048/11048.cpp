#include <iostream>
#define Maxx(a, b) (a > b ? a : b)
#define Max(a, b, c) (Maxx(a, b) > Maxx(b, c) ? Maxx(a, b) : Maxx(b, c))

using namespace std;

int N, M;

int map[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 2; i <= M; i++)
	{
		map[1][i] = map[1][i - 1] + map[1][i];
	}

	for (int i = 2; i <= N; i++)
	{
		map[i][1] = map[i - 1][1] + map[i][1];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			map[i][j] = map[i][j] + Max(map[i - 1][j], map[i][j - 1], map[i - 1][j - 1]);
		}
	}

	cout << map[N][M] << "\n";

	return 0;
}