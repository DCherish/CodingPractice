#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int cnt = 0;

void function(int x, int y, int Size)
{
	if (x == r && y == c)
	{
		cout << cnt << "\n";
		return;
	}

	if (r < x + Size && x <= r && c < y + Size && y <= c)
	{
		function(x, y, Size / 2);
		function(x, y + Size / 2, Size / 2);
		function(x + Size / 2, y, Size / 2);
		function(x + Size / 2, y + Size / 2, Size / 2);
	}
	else
	{
		cnt += (int)pow(Size, 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c;

	function(0, 0, (int)pow(2, N));

	return 0;
}