#include <iostream>
#include <algorithm>

using namespace std;

int N;

int twocnt = 0;
int fivecnt = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 2; i <= N; i = i * 2)
	{
		twocnt += N / i;
	}

	for (int i = 5; i <= N; i = i * 5)
	{
		fivecnt += N / i;
	}

	cout << min(twocnt, fivecnt) << "\n";

	return 0;
}