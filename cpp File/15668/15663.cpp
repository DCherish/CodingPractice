#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;
bool visited[10];

void DFS(int depth, int gap)
{
	if (depth == M)
	{
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == true) continue;

		if (depth == 0)
		{
			visited[i] = true;
			DFS(depth + 1, visited[i]);
			visited[i] = false;
		}
		else if (depth == 1)
		{
			visited[i] = true;
			DFS(depth + 1, visited[i] - gap);
			visited[i] = false;
		}
		else
		{
			visited[i] = true;
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