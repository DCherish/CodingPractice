#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class pnt
{
public:
	int x;
	int y;
};

int N;
vector<pnt> vec;

bool cmp(pnt p1, pnt p2)
{
	if (p1.x == p2.x)
	{
		return p1.y < p2.y;
	}
	else return p1.x < p2.x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pnt np;

		cin >> np.x >> np.y;

		vec.push_back(np);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].x << " " << vec[i].y << "\n";
	}

	return 0;
}