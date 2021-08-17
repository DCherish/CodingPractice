#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> vec;
vector<int> ans;

bool visited[10];

void DFS(int depth, int idx)
{
	if (depth == M)
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}

		cout << "\n";

		return;
	}

	int prev = -1;

	for (int i = idx; i < N; i++)
	{
		if (visited[i] == false && prev != vec[i])
		{
			visited[i] = true;
			ans.push_back(vec[i]);
			prev = vec[i];
			DFS(depth + 1, i + 1);
			ans.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), less<int>());

	DFS(0, 0);

	return 0;
}