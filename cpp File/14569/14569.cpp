#include <iostream>
#include <vector>

using namespace std;

int N, M, k, t, p, q;

long long subject[1000];

vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> t;

			subject[i] += ((long long)1 << t);
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> p;

		long long temp = 0;
		int cnt = 0;

		for (int j = 0; j < p; j++)
		{
			cin >> q;

			temp += ((long long)1 << q);
		}

		for (int j = 0; j < N; j++)
		{
			if ((subject[j] & temp) == subject[j]) cnt++;
		}

		ans.push_back(cnt);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}