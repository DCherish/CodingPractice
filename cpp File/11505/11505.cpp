#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;

struct info
{
	int a;
	int b;
	ll c;
};

int N, M, K;

vector<ll> vec;
vector<ll> tree;
vector<info> cmd;
vector<ll> ans;

ll make_SegmentTree(int node, int start, int end)
{
	if (start == end) return tree[node] = vec[start] % MOD;

	int mid = (start + end) / 2;
	ll left_result = make_SegmentTree(node * 2, start, mid);
	ll right_result = make_SegmentTree(node * 2 + 1, mid + 1, end);

	tree[node] = (left_result * right_result) % MOD;

	return tree[node];
}

ll mul(int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return 1;
	if (l <= start && end <= r) return tree[node];

	int mid = (start + end) / 2;
	ll left_result = mul(node * 2, start, mid, l, r);
	ll right_result = mul(node * 2 + 1, mid + 1, end, l, r);

	return (left_result * right_result) % MOD;
}

ll update(int node, int start, int end, int idx, ll value)
{
	if (idx < start || idx > end) return tree[node];
	if (start == end) return tree[node] = value;

	int mid = (start + end) / 2;
	ll left_result = update(node * 2, start, mid, idx, value);
	ll right_result = update(node * 2 + 1, mid + 1, end, idx, value);

	tree[node] = (left_result * right_result) % MOD;

	return tree[node];
}

void solve()
{
	int tree_ht = (int)ceil(log2(N));
	int tree_sz = pow(2, tree_ht + 1);
	tree.resize(tree_sz);
	make_SegmentTree(1, 0, N - 1);

	for (int i = 0; i < cmd.size(); i++)
	{
		int temp = cmd[i].a;

		if (temp == 1)
		{
			int idx = cmd[i].b - 1;
			ll value = cmd[i].c;

			update(1, 0, N - 1, idx, value);
		}
		else
		{
			int idx1 = cmd[i].b - 1;
			int idx2 = cmd[i].c - 1;

			ll result = mul(1, 0, N - 1, idx1, idx2);

			result %= MOD;

			ans.push_back(result);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;

		cmd.push_back({ a, b, c });
	}

	solve();

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}