#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

struct info
{
	int a;
	int b;
};

vector<int> vec;
vector<int> tree;
vector<info> cmd;
vector<int> ans;

int N, M;

int make_SegmentTree(int node, int start, int end)
{
	if (start == end) return tree[node] = vec[start];

	int mid = (start + end) / 2;
	int left_result = make_SegmentTree(node * 2, start, mid);
	int right_result = make_SegmentTree(node * 2 + 1, mid + 1, end);

	tree[node] = min(left_result, right_result);

	return tree[node];
}

int min_SegmentTree(int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return INT_MAX;
	if (l <= start && end <= r) return tree[node];

	int mid = (start + end) / 2;
	int left_result = min_SegmentTree(node * 2, start, mid, l, r);
	int right_result = min_SegmentTree(node * 2 + 1, mid + 1, end, l, r);

	return min(left_result, right_result);
}

void solve()
{
	int tree_ht = (int)ceil(log2(N));
	int tree_sz = pow(2, tree_ht + 1);
	tree.resize(tree_sz);
	make_SegmentTree(1, 0, N - 1);

	for (int i = 0; i < cmd.size(); i++)
	{
		int idx1 = cmd[i].a - 1;
		int idx2 = cmd[i].b - 1;

		int result = min_SegmentTree(1, 0, N - 1, idx1, idx2);

		ans.push_back(result);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		cmd.push_back({ a, b });
	}

	solve();

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}