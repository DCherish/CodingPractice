#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	int x;
	int y;
};

vector<info> House;
vector<info> Chicken;

vector<info> vec;

int ans, N, M;
int arr[51][51];
bool Visit_C[14];

int cal()
{
	int sum = 0;

	for (int i = 0; i < House.size(); i++)
	{
		int x = House[i].x;
		int y = House[i].y;

		int dist = INT_MAX;

		for (int j = 0; j < vec.size(); j++)
		{
			int xx = vec[j].x;
			int yy = vec[j].y;

			int ddist = abs(x - xx) + abs(y - yy);

			dist = min(dist, ddist);
		}

		sum = sum + dist;
	}

	return sum;
}

void DFS(int idx, int cnt)
{
	if (cnt == M)
	{
		ans = min(ans, cal());
		return;
	}

	for (int i = idx; i < Chicken.size(); i++)
	{
		if (Visit_C[i] == true) continue;
		Visit_C[i] = true;

		vec.push_back(Chicken[i]);
		DFS(i + 1, cnt + 1);

		Visit_C[i] = false;
		vec.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ans = INT_MAX;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				House.push_back({ i, j });
			}
			else if (arr[i][j] == 2)
			{
				Chicken.push_back({ i, j });
			}
		}
	}

	DFS(0, 0);

	cout << ans << "\n";

	return 0;
}