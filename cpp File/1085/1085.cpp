#include <iostream>

using namespace std;

int x, y, w, h;
int mindistance = 9999;

int order[4];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> y >> w >> h;

	order[0] = x;
	order[1] = y;
	order[2] = w - x;
	order[3] = h - y;

	for (int i = 0; i < 4; i++)
	{
		if (order[i] < mindistance)
		{
			mindistance = order[i];
		}
	}

	cout << mindistance << "\n";

	return 0;
}