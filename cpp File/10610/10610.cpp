#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string N, ans;
vector<int> vec;

bool state = true;
int sum;

void solve()
{
	if (sum % 3 != 0)
	{
		state = false;
		return;
	}

	sort(vec.begin(), vec.end(), greater<int>());

	if (vec[vec.size() - 1] != 0)
	{
		state = false;
		return;
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			ans += to_string(vec[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, N);

	for (int i = 0; i < N.length(); i++)
	{
		int num = (int)N[i] - (int)'0';

		sum += num;

		vec.push_back(num);
	}

	solve();

	if (state == true)
	{
		cout << ans << "\n";
	}
	else cout << "-1\n";

	return 0;
}