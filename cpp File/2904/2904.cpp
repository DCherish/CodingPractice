#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 1000000

using namespace std;

int N;
int ans_num = 1;
int ans_cnt = 0;

vector<int> prime;
vector<int> p_cnt;

vector<int> vec;
vector<vector <int>> v_cnt;
vector<int> gcd_cnt;

bool p_check[1000001];

void cal_prime()
{
	memset(p_check, true, sizeof(p_check));

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (p_check[i] == false) continue;

		for (int j = i * i; j <= MAX; j = j + i)
		{
			p_check[j] = false;
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (p_check[i] == true)
		{
			prime.push_back(i);
		}
	}
}

void cal_cnt(int idx, int x)
{
	p_cnt.resize(prime.size());
	v_cnt[idx].resize(prime.size());

	for (int i = 0; i < prime.size(); i++)
	{
		while (x % prime[i] == 0)
		{
			p_cnt[i]++;
			v_cnt[idx][i]++;
			x /= prime[i];

			if (x == 1) break;
		}

		if (x == 1) break;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cal_prime();
	v_cnt.resize(N);
	gcd_cnt.resize(prime.size());

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);

		cal_cnt(i, a);
	}

	for (int i = 0; i < p_cnt.size(); i++)
	{
		if (p_cnt[i] >= N)
		{
			for (int j = 0; j < p_cnt[i] / N; j++)
			{
				ans_num *= prime[i];
				gcd_cnt[i]++;
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < prime.size(); j++)
		{
			if (gcd_cnt[j] > v_cnt[i][j])
			{
				ans_cnt += gcd_cnt[j] - v_cnt[i][j];
			}
		}
	}

	cout << ans_num << " " << ans_cnt << "\n";

	return 0;
}