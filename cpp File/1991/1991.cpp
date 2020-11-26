#include <iostream>

using namespace std;

int N;
char root, l, r;
char tree[26][2] = { '.', };

void preorder(char idx)
{
	if (idx == '.') return;
	else
	{
		cout << idx;
		preorder(tree[(int)idx - (int)'A'][0]);
		preorder(tree[(int)idx - (int)'A'][1]);
	}
}

void inorder(char idx)
{
	if (idx == '.') return;
	else
	{
		inorder(tree[(int)idx - (int)'A'][0]);
		cout << idx;
		inorder(tree[(int)idx - (int)'A'][1]);
	}
}

void postorder(char idx)
{
	if (idx == '.') return;
	else
	{
		postorder(tree[(int)idx - (int)'A'][0]);
		postorder(tree[(int)idx - (int)'A'][1]);
		cout << idx;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> root >> l >> r;

		tree[(int)root - (int)'A'][0] = l;
		tree[(int)root - (int)'A'][1] = r;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}