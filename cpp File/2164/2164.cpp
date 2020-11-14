#include <iostream>
#include <deque>

using namespace std;
deque<int> DQ;

int N;
int cnt = 1;

int result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		DQ.push_back(i);
	}

	while (!DQ.empty())
	{
		result = DQ.front();
		DQ.pop_front();

		if (cnt % 2 == 1)
		{
			cnt++;
		}
		else
		{
			DQ.push_back(result);
			cnt++;
		}
	}

	cout << result << "\n";

	return 0;
}