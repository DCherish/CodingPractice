#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
deque<int> DQplus;
deque<int> DQminus;

int N, num;
int frt, bck;
int sum = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num > 0)
		{
			DQplus.push_back(num);
		}
		else
		{
			DQminus.push_back(num);
		}
	}

	sort(DQplus.begin(), DQplus.end(), greater<int>());
	sort(DQminus.begin(), DQminus.end(), less<int>());

	while (!DQplus.empty())
	{
		frt = DQplus.front();
		DQplus.pop_front();

		if (DQplus.empty())
		{
			sum += frt;
			break;
		}
		else
		{
			bck = DQplus.front();
			DQplus.pop_front();
		}

		if (frt > 1)
		{
			if (bck > 1) sum += frt * bck;
			else sum += frt + bck;
		}
		else if (frt > 0 && frt <= 1)
		{
			sum += frt + bck;
		}
	}

	while (!DQminus.empty())
	{
		frt = DQminus.front();
		DQminus.pop_front();

		if (DQminus.empty())
		{
			sum += frt;
			break;
		}
		else
		{
			bck = DQminus.front();
			DQminus.pop_front();
		}

		if (bck <= 0) sum += frt * bck;
		else sum += frt + bck;
	}

	cout << sum << "\n";

	return 0;
}