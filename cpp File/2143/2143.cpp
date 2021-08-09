#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m;

ll T, cnt;

vector<ll> n_vec, m_vec;
vector<ll> v1, v2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		n_vec.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		ll sum = n_vec[i];
		v1.push_back(sum);

		for (int j = i + 1; j < n; j++)
		{
			sum += n_vec[j];
			v1.push_back(sum);
		}
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;

		m_vec.push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		ll sum = m_vec[i];
		v2.push_back(sum);

		for (int j = i + 1; j < m; j++)
		{
			sum += m_vec[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(), v1.end(), less<ll>());
	sort(v2.begin(), v2.end(), less<ll>());

	for (int i = 0; i < v1.size(); i++)
	{
		ll l = lower_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
		ll r = upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();

		cnt += r - l;
	}

	cout << cnt << "\n";

	return 0;
}