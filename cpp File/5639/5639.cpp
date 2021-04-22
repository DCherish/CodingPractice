#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preOrder;

int num;

void postOrder(int start, int end)
{
	if (start > end) return;

	int rootNum = preOrder[start];
	int last = end;

	while (preOrder[last] > rootNum)
	{
		last--;
	}

	postOrder(start + 1, last);
	postOrder(last + 1, end);

	cout << rootNum << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> num)
	{
		preOrder.push_back(num);
	}

	postOrder(0, preOrder.size() - 1);

	return 0;
}