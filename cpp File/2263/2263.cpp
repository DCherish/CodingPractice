#include <iostream>

using namespace std;

int inOrder[100001];
int postOrder[100001];
int idx[100001];

void preOrder(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd) return;

	int rootIndex = idx[postOrder[postEnd]];

	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;

	cout << inOrder[rootIndex] << " ";

	preOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	preOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> inOrder[i];
		idx[inOrder[i]] = i;

	}

	for (int i = 1; i <= n; i++)
	{
		cin >> postOrder[i];
	}

	preOrder(1, n, 1, n);

	return 0;
}