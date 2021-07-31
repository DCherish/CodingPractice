#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	long long a;
	long long b;
};

int N;
long long a, b;
long long ans = 0;

bool state = true;
bool check = false;

long long money = 0;
long long minB = LLONG_MAX;

vector<info> vec;

long long gcd(long long x, long long y) // 유클리드 호제법
{
	long long result;

	if (x < y) swap(x, y);

	while (y != 0)
	{
		result = x % y;
		x = y;
		y = result;
	}

	return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		vec.push_back({ a, b });
	}

	for (int i = 0; i < vec.size(); i++)
	{
		long long va = vec[i].a;
		long long vb = vec[i].b;

		if (money + va >= 0) // 충전불필요
		{
			if (money + va != vb)
			{
				state = false;
				break;
			}
		}
		else // 충전필요
		{
			long long temp = vb - money - va; // 충전금액 계산

			if (vb != 0 && vb < minB) // 최소잔여금액 갱신
			{
				check = true;
				minB = vb;
			}

			if (ans == 0) ans = temp; // 최소충전금액 계산
			else
			{
				ans = gcd(temp, ans); // 최소충전금액 계산

				if (ans <= minB && check == true) // 최소충전금액 <= 최소잔여금액 // 필요이상 충전
				{
					state = false;
					break;
				}
			}
		}

		money = vb;
	}

	if (state == true && ans > 0)
	{
		cout << ans << "\n";
	}
	else if (state == true && ans == 0)
	{
		cout << 1 << "\n";
	}
	else cout << -1 << "\n";

	return 0;
}