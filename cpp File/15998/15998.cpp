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

long long gcd(long long x, long long y) // ��Ŭ���� ȣ����
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

		if (money + va >= 0) // �������ʿ�
		{
			if (money + va != vb)
			{
				state = false;
				break;
			}
		}
		else // �����ʿ�
		{
			long long temp = vb - money - va; // �����ݾ� ���

			if (vb != 0 && vb < minB) // �ּ��ܿ��ݾ� ����
			{
				check = true;
				minB = vb;
			}

			if (ans == 0) ans = temp; // �ּ������ݾ� ���
			else
			{
				ans = gcd(temp, ans); // �ּ������ݾ� ���

				if (ans <= minB && check == true) // �ּ������ݾ� <= �ּ��ܿ��ݾ� // �ʿ��̻� ����
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