#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class info
{
public:
	int x;
	int y;
};

int N, x, tempidx, tempcnt;
vector<info> vec;
int cnt[1000000];

bool cmp(info a, info b)
{
	return a.x < b.x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		vec.push_back({ x, i });
	}

	sort(vec.begin(), vec.end(), cmp);

	tempidx = vec[0].x;
	tempcnt = 0;
	cnt[vec[0].y] = 0;

	for (int i = 1; i < N; i++)
	{
		if (vec[i].x == tempidx)
		{
			cnt[vec[i].y] = tempcnt;
		}
		else
		{
			cnt[vec[i].y] = tempcnt + 1;
			tempidx = vec[i].x;

			tempcnt++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << cnt[i] << " ";
	}

	cout << "\n";

	// 시간절약 TIP
	// sort(a, b) // 기본 오름차순 12345
	// sort(a, b, less<int>()) // 오름차순 12345
	// sort(a, b, greater<int>()) // 내림차순 54321
	// sort(a, b, cmp) // cmp 지정

	// 배운것
	// sort index 다루기 ★
	// pair lower_bound ★

	return 0;
}