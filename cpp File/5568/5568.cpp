#include <iostream>
#include <string>
#include <set>

using namespace std;

int n, k, c, ans;
int card[10];
bool visited[10];

set<string> info;

void solve(int depth, string str)
{
	if (depth == k)
	{
		if (info.count(str) == 0)
		{
			info.insert(str);
			ans++;
		}

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == true) continue;

		visited[i] = true;
		solve(depth + 1, str + to_string(card[i]));
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> card[i];
	}

	solve(0, "");

	cout << ans << "\n";

	return 0;
}