#include <iostream>
#include <algorithm>

using namespace std;

struct info
{
	int left;
	int right;
};

int N, parent, lchild, rchild;
int root, nodeidx;

int node[10001];
info tree[10001];
int low[10001];
int high[10001];

void DFS(int num, int cnt)
{
	if (tree[num].left > 0)
	{
		DFS(tree[num].left, cnt + 1);
	}

	low[cnt] = min(low[cnt], nodeidx);
	high[cnt] = max(high[cnt], nodeidx++);

	if (tree[num].right > 0)
	{
		DFS(tree[num].right, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		low[i] = 77777;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> parent >> lchild >> rchild;

		node[parent]++;

		if (lchild != -1)
		{
			node[lchild]++;
		}

		tree[parent].left = lchild;

		if (rchild != -1)
		{
			node[rchild]++;
		}

		tree[parent].right = rchild;
	}

	for (int i = 1; i <= N; i++)
	{
		if (node[i] == 1)
		{
			root = i;
			break;
		}
	}

	nodeidx = 1;
	DFS(root, 1);

	int result = high[1] - low[1] + 1;
	int level = 1;

	for (int i = 2; i <= N; i++)
	{
		int temp = high[i] - low[i] + 1;

		if (temp > result)
		{
			result = temp;
			level = i;
		}
	}

	cout << level << " " << result << "\n";

	return 0;
}