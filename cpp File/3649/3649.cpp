#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int x, n;
int len[1000000];
vector<string> ans;

int l, r, sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		if (cin >> x)
		{
			x *= 10000000;

			cin >> n;

			for (int i = 0; i < n; i++)
			{
				cin >> len[i];
			}

			sort(len, len + n, less<int>());

			l = 0;
			r = n - 1;
			sum = 0;

			while (l < r)
			{
				sum = len[l] + len[r];

				if (sum < x) l++;
				else if (sum > x) r--;
				else break;
			}

			if (sum == x)
			{
				string str = "yes " + to_string(len[l]) + " " + to_string(len[r]);
				ans.push_back(str);
			}
			else
			{
				ans.push_back("danger");
			}
		}
		else break;
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}