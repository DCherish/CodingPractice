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

int N, M;

vector<int> vec;
vector<int> min_tree;
vector<int> max_tree;
vector<info> cmd;
vector<info> ans;

int make_minSegmentTree(int node, int start, int end)
{
	if (start == end) return min_tree[node] = vec[start];

	int mid = (start + end) / 2;
	int left_result = make_minSegmentTree(node * 2, start, mid);
	int right_result = make_minSegmentTree(node * 2 + 1, mid + 1, end);

	min_tree[node] = min(left_result, right_result);

	return min_tree[node];
}

int make_maxSegmentTree(int node, int start, int end)
{
	if (start == end) return max_tree[node] = vec[start];

	int mid = (start + end) / 2;
	int left_result = make_maxSegmentTree(node * 2, start, mid);
	int right_result = make_maxSegmentTree(node * 2 + 1, mid + 1, end);

	max_tree[node] = max(left_result, right_result);

	return max_tree[node];
}

int min_SegmentTree(int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return INT_MAX;
	if (l <= start && end <= r) return min_tree[node];

	int mid = (start + end) / 2;
	int left_result = min_SegmentTree(node * 2, start, mid, l, r);
	int right_result = min_SegmentTree(node * 2 + 1, mid + 1, end, l, r);

	return min(left_result, right_result);
}

int max_SegmentTree(int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return INT_MIN;
	if (l <= start && end <= r) return max_tree[node];

	int mid = (start + end) / 2;
	int left_result = max_SegmentTree(node * 2, start, mid, l, r);
	int right_result = max_SegmentTree(node * 2 + 1, mid + 1, end, l, r);

	return max(left_result, right_result);
}

void solve()
{
	int tree_ht = (int)ceil(log2(N));
	int tree_sz = pow(2, tree_ht + 1);
	min_tree.resize(tree_sz);
	max_tree.resize(tree_sz);
	make_minSegmentTree(1, 0, N - 1);
	make_maxSegmentTree(1, 0, N - 1);

	for (int i = 0; i < cmd.size(); i++)
	{
		int idx1 = cmd[i].a - 1;
		int idx2 = cmd[i].b - 1;

		int result1 = min_SegmentTree(1, 0, N - 1, idx1, idx2);
		int result2 = max_SegmentTree(1, 0, N - 1, idx1, idx2);

		ans.push_back({ result1, result2 });
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
		cout << ans[i].a << " " << ans[i].b << "\n";
	}

	return 0;
}