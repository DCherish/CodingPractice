#include <iostream>
#include <deque>

using namespace std;

struct pnt
{
	int first;
	int second;
};

int N, L;
int arr[5000000];

deque<pnt> DQ;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (!DQ.empty() && DQ.front().second <= i - L)
		{
			DQ.pop_front();
		}

		while (!DQ.empty() && DQ.back().first > arr[i])
		{
			DQ.pop_back();
		}

		DQ.push_back({ arr[i], i });

		cout << DQ.front().first << " ";
	}

	cout << "\n";

	return 0;
}