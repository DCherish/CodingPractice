#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct info
{
	int x;
	int y;
};

int N, M;
ll arr[100001];
ll sum[100001];

vector<ll> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sum[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;

		ans.push_back(sum[b] - sum[a - 1]);
	}

	for (int i = 0; i < M; i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}