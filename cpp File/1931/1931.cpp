#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class info
{
public:
	int starttime;
	int endtime;
};

int N, s, e;
vector<info> vec;

int temp;
int cnt = 0;

bool cmp(info a, info b)
{
	if (a.endtime == b.endtime)
	{
		return a.starttime < b.starttime;
	}
	else return a.endtime < b.endtime;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;

		vec.push_back({ s, e });
	}

	sort(vec.begin(), vec.end(), cmp);

	temp = vec[0].endtime;
	cnt++;

	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i].starttime >= temp)
		{
			temp = vec[i].endtime;
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}