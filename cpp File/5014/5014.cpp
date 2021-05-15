#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct info
{
	int num;
	int cnt;
};

bool visited[1000001];

int F, S, G, U, D;

int result = 0;

queue<info> Q;

void BFS()
{
	visited[S] = true;
	Q.push({ S, 0 });

	while (!Q.empty())
	{
		int temp_num = Q.front().num;
		int temp_cnt = Q.front().cnt;
		Q.pop();

		if (temp_num == G)
		{
			result = temp_cnt;
			return;
		}

		if (temp_num + U <= F && visited[temp_num + U] == false)
		{
			visited[temp_num + U] = true;

			Q.push({ temp_num + U, temp_cnt + 1 });
		}

		if (temp_num - D >= 1 && visited[temp_num - D] == false)
		{
			visited[temp_num - D] = true;

			Q.push({ temp_num - D, temp_cnt + 1 });
		}
	}

	result = -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> F >> S >> G >> U >> D;

	for (int i = 1; i <= F; i++)
	{
		visited[i] = false;
	}

	BFS();

	if (result == -1)
	{
		cout << "use the stairs\n";
	}
	else cout << result << "\n";

	return 0;
}