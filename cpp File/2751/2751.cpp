#include <iostream>
#include <queue>

using namespace std;

class cmp
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

priority_queue<int, vector<int>, cmp> PQ;

int N, num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		PQ.push(num);
	}

	while (!PQ.empty())
	{
		cout << PQ.top() << "\n";
		PQ.pop();
	}

	return 0;
}