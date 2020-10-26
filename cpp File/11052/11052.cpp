#include <iostream>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int N;
int p[10001] = { 0, };
int c[10001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> p[i];
	}

	c[1] = p[1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			c[i] = Max(c[i], p[j] + c[i-j]);
			c[i] = Max(c[i], p[i]);
		}
	}

	cout << c[N] << "\n";

	return 0;
}