#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class Elem
{
public:
	int idx;
	int cnt;
};

int N, M;

char arr[300000];
bool visited[300000];

int mincnt;

map<int, int> mat;

void init()
{
	mincnt = 999999;

	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
	}
}

void BFS(int a, int b)
{
	queue<Elem> Q;

	Q.push({ a, 0 });
	visited[a - 1] = true;

	while (!Q.empty())
	{
		int nidx = Q.front().idx;
		int ncnt = Q.front().cnt;

		Q.pop();

		if (arr[nidx] == '.')
		{

		}
		else
		{
		}
	}
}

void matching()
{
	stack<int> S;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == '(')
		{
			S.push(i);
			continue;
		}

		if (arr[i] == ')')
		{
			int pnt = S.top();
			S.pop();

			mat[pnt] = i;
			mat[i] = pnt;
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
		cin >> arr[i];
	}

	matching();

	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;

		init();

		BFS(a - 1, b - 1);

		cout << mincnt << "\n";
	}
}