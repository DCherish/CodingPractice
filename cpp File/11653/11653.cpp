#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	M = N;

	if (N != 1)
	{
		for (int i = 2; i <= sqrt(N); i++)
		{
			while (M % i == 0)
			{
				ans.push_back(i);
				M /= i;
			}
		}

		if (M > 1) ans.push_back(M);

		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}

	return 0;
}