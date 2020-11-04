#include <iostream>
#include <vector>
#include <queue>
#define Max(a, b) (a > b ? a : b)

using namespace std;

int k;
char c;

int maxpre[10];
vector<int> maxpost[10];
vector<int> maxanswer;
int maxresult[10];

int minpre[10];
vector<int> minpost[10];
vector<int> minanswer;
int minresult[10];

int temp = 9;

class g_cmp
{
public:
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

class l_cmp
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> c;

		if (c == '<')
		{
			maxpre[i + 1]++;
			maxpost[i].push_back(i + 1);

			minpre[i + 1]++;
			minpost[i].push_back(i + 1);
		}
		else
		{
			maxpre[i]++;
			maxpost[i + 1].push_back(i);

			minpre[i]++;
			minpost[i + 1].push_back(i);
		}
	}

	priority_queue<int, vector<int>, g_cmp> maxpq;
	priority_queue<int, vector<int>, l_cmp> minpq;

	for (int i = 0; i < k + 1; i++)
	{
		if (maxpre[i] == 0)
		{
			maxpq.push(i);
		}
	}

	while (!maxpq.empty())
	{
		int idx = maxpq.top();
		maxpq.pop();

		maxanswer.push_back(idx);

		for (int i = 0; i < maxpost[idx].size(); i++)
		{
			if (--maxpre[maxpost[idx][i]] == 0)
			{
				maxpq.push(maxpost[idx][i]);
			}
		}
	}

	for (int i = 0; i < k + 1; i++)
	{
		if (minpre[i] == 0)
		{
			minpq.push(i);
		}
	}

	while (!minpq.empty())
	{
		int idx = minpq.top();
		minpq.pop();

		minanswer.push_back(idx);

		for (int i = 0; i < minpost[idx].size(); i++)
		{
			if (--minpre[minpost[idx][i]] == 0)
			{
				minpq.push(minpost[idx][i]);
			}
		}
	}

	for (int i = maxanswer.size() - 1; i >= 0; i--)
	{
		maxresult[maxanswer[i]] = temp;
		temp--;
	}

	temp = 0;

	for (int i = 0; i < minanswer.size(); i++)
	{
		minresult[minanswer[i]] = temp;
		temp++;
	}

	for (int i = 0; i < k + 1; i++)
	{
		cout << maxresult[i];
	}

	cout << "\n";

	for (int i = 0; i < k + 1; i++)
	{
		cout << minresult[i];
	}

	cout << "\n";

	return 0;
}