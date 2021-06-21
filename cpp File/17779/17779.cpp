#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

struct pnt
{
	int x;
	int y;
};

int N;
int A[20][20];
int Label[20][20];
pnt pos[4];
int ans = INT_MAX;

void cal()
{
	int Sum[6] = { 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Sum[Label[i][j]] += A[i][j];
		}
	}

	sort(Sum, Sum + 6);
	int diff = Sum[5] - Sum[1];
	ans = min(ans, diff);
}

void labeling(int x, int y, int p, int q)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Label[i][j] = 5;
		}
	}

	int SubArea = 0;
	for (int i = 0; i < pos[1].x; i++)
	{
		if (i >= pos[0].x) SubArea++;

		for (int j = 0; j <= pos[0].y - SubArea; j++)
		{
			Label[i][j] = 1;
		}
	}

	int PlusArea = 0;
	for (int i = 0; i <= pos[2].x; i++)
	{
		if (i > pos[0].x) PlusArea++;

		for (int j = pos[0].y + 1 + PlusArea; j < N; j++)
		{
			Label[i][j] = 2;
		}
	}

	SubArea = 0;
	for (int i = N - 1; i >= pos[1].x; i--)
	{
		if (i < pos[3].x) SubArea++;

		for (int j = 0; j < pos[3].y - SubArea; j++)
		{
			Label[i][j] = 3;
		}
	}

	PlusArea = 0;
	for (int i = N - 1; i > pos[2].x; i--)
	{
		if (i <= pos[3].x) PlusArea++;

		for (int j = pos[3].y + PlusArea; j < N; j++)
		{
			Label[i][j] = 4;
		}
	}

	cal();
}

bool isValid(int x, int y, int d1, int d2)
{
	if (x + d1 >= N || y - d1 < 0) return false;
	if (x + d2 >= N || y + d2 >= N) return false;
	if (x + d1 + d2 >= N || y - d1 + d2 >= N) return false;
	if (x + d1 + d2 >= N || y - d1 + d2 < 0) return false;

	return true;
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			for (int D1 = 1; D1 <= j; D1++)
			{
				for (int D2 = 1; D2 < N - j; D2++)
				{
					if (isValid(i, j, D1, D2) == true)
					{
						pos[0].x = i;
						pos[0].y = j;

						pos[1].x = i + D1;
						pos[1].y = j - D1;

						pos[2].x = i + D2;
						pos[2].y = j + D2;

						pos[3].x = i + D1 + D2;
						pos[3].y = j - D1 + D2;

						labeling(i, j, D1, D2);
					}
				}
			}
		}
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
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	solve();

	cout << ans << "\n";

	return 0;
}