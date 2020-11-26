#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int N, num, root, rm_num;
vector<int> parent[50];
bool visited[50];
stack<int> S;
int cnt = 0;

void DFS()
{
	S.push(root);
	visited[root] = true;

	while (!S.empty())
	{
		int idx = S.top();
		S.pop();

		if (parent[idx].size() == 0)
		{
			cnt++;
			continue;
		}
		else if (parent[idx].size() == 1)
		{
			if (parent[idx][0] == rm_num)
			{
				cnt++;
				continue;
			}
		}

		for (int i = 0; i < parent[idx].size(); i++)
		{
			if (visited[parent[idx][i]] == false)
			{
				if (parent[idx][i] == rm_num) continue;

				visited[parent[idx][i]] = true;
				S.push(parent[idx][i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		if (num != -1)
		{
			parent[num].push_back(i);
		}
		else
		{
			root = i;
		}
	}

	cin >> rm_num;

	if (root != rm_num)
	{
		DFS();
	}

	cout << cnt << "\n";

	return 0;
}