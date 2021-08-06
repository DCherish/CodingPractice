#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct info
{
	int v;
	int idx;
};

int N;

vector<info> vec;
vector<int> tree;
vector<int> ans;

bool cmp_v(info a, info b)
{
	return a.v > b.v;
}

bool cmp_idx(info a, info b)
{
	return a.idx < b.idx;
}

int cnt_SegmentTree(int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return 0;
	if (l <= start && end <= r) return tree[node];

	int mid = (start + end) / 2;
	int left_result = cnt_SegmentTree(node * 2, start, mid, l, r);
	int right_result = cnt_SegmentTree(node * 2 + 1, mid + 1, end, l, r);

	return left_result + right_result;
}

int update_SegmentTree(int node, int start, int end, int idx, int value)
{
	if (idx < start || end < idx) return tree[node];
	if (start == end)
	{
		tree[node] += value;
		return tree[node];
	}

	int mid = (start + end) / 2;
	int left_result = update_SegmentTree(node * 2, start, mid, idx, value);
	int right_result = update_SegmentTree(node * 2 + 1, mid + 1, end, idx, value);

	tree[node] = left_result + right_result;

	return tree[node];
}

void solve()
{
	int tree_ht = (int)ceil(log2(N));
	int tree_sz = pow(2, tree_ht + 1);
	tree.resize(tree_sz);

	for (int i = 0; i < vec.size(); i++)
	{
		int cnt = 0;

		cnt = cnt_SegmentTree(1, 0, N - 1, 0, vec[i].v);

		ans.push_back(cnt + 1);

		update_SegmentTree(1, 0, N - 1, vec[i].v, 1);
	}
}

void sort_vec()
{
	sort(vec.begin(), vec.end(), cmp_v);

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].v = i;
	}

	sort(vec.begin(), vec.end(), cmp_idx);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		vec.push_back({ a, i });
	}

	sort_vec();

	solve();

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}