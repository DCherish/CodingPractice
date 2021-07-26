#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, num;

vector<long long> L;
vector<long long> R;

vector<int> l_vec;
vector<int> r_vec;

void DFS(int depth, long long cnt, bool flag)
{
	if (flag == true && depth == l_vec.size())
	{
		L.push_back(cnt);
		return;
	}
	else if (flag == false && depth == r_vec.size())
	{
		R.push_back(cnt);
		return;
	}

	if (flag == true) DFS(depth + 1, cnt + l_vec[depth], flag);
	else DFS(depth + 1, cnt + r_vec[depth], flag);

	DFS(depth + 1, cnt, flag);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (i < (N / 2))
		{
			l_vec.push_back(num);
		}
		else
		{
			r_vec.push_back(num);
		}
	}

	DFS(0, 0, true);
	DFS(0, 0, false);

	sort(L.begin(), L.end(), less<long long>());
	sort(R.begin(), R.end(), less<long long>());

	long long ans = 0;

	for (int i = 0; i < L.size(); i++)
	{
		int idx = upper_bound(R.begin(), R.end(), C - L[i]) - R.begin();

		if (idx != 0)
		{
			ans += idx;
		}
	}

	cout << ans << "\n";

	return 0;
}