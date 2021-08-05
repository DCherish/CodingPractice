#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

int n;

vector<int> temp;
vector<int> vec;
vector<int> tree;

int make_SegmentTree(int node, int start, int end)
{
	if (start == end) return tree[node] = vec[start];

	int mid = (start + end) / 2;
	int left_result = make_SegmentTree(node * 2, start, mid);
	int right_result = make_SegmentTree(node * 2 + 1, mid + 1, end);

	tree[node] = max(left_result, right_result);
	
	return tree[node];
}

void solve()
{
	int tree_ht = (int)ceil(log2(n - 1));
	int tree_sz = pow(2, tree_ht + 1);
	tree.resize(tree_sz);
	make_SegmentTree(1, 0, n - 2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n)
	{
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;

			temp.push_back(a);
		}

		for (int i = 0; i < n - 1; i++)
		{
			int prev = temp[i];
			int next = temp[i + 1];

			int pick = min(prev, next);

			vec.push_back(pick);
		}

		solve();
	}

	return 0;
}