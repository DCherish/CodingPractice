#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n;

vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n)
	{
		ll num = 1;
		int cnt = 1;

		while (true)
		{
			if (num % n == 0)
			{
				ans.push_back(cnt);
				break;
			}
			else
			{
				num %= n;
				num *= 10;
				num += 1;

				cnt++;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}