#include <iostream>
#include <queue>

using namespace std;

struct info
{
	int pay;
	int day;
};

class cmp
{
public:
	bool operator()(info a, info b)
	{
		return a.pay < b.pay;
	}
};

int n, p, d, sum;
bool visited[10001];

priority_queue<info, vector<info>, cmp> PQ;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;

		PQ.push({ p, d });
	}

	while (!PQ.empty())
	{
		int np = PQ.top().pay;
		int nd = PQ.top().day;
		PQ.pop();

		for (int i = nd; i >= 1; i--)
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				sum += np;
				break;
			}
		}
	}

	cout << sum << "\n";

	return 0;
}