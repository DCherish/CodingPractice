#include <iostream>

using namespace std;

int N;
char c[128][128];

int w_cnt = 0;
int b_cnt = 0;

void recursion(int x, int y, int Size)
{
	char temp = c[x][y];

	for (int i = x; i < x + Size; i++)
	{
		for (int j = y; j < y + Size; j++)
		{
			if (temp != c[i][j])
			{
				temp = '7';
			}

			if (temp == '7')
			{
				recursion(x, y, Size / 2);
				recursion(x + Size / 2, y, Size / 2);
				recursion(x, y + Size / 2, Size / 2);
				recursion(x + Size / 2, y + Size / 2, Size / 2);
				return;
			}
		}
	}

	if (temp == '0')
	{
		w_cnt++;
	}
	else if (temp == '1')
	{
		b_cnt++;
	}

	return;
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
			cin >> c[i][j];
		}
	}

	recursion(0, 0, N);

	cout << w_cnt << "\n";
	cout << b_cnt << "\n";

	return 0;
}