#include <iostream>
#include <vector>
#include <queue>
#define Max(a, b) (a > b ? a : b)

using namespace std;

class info
{
public:
	int num;
	int time;
};

int n, m;
int fm, to, ck;

int pre[10000];
vector<info> post[10000];
vector<info> rvrs[10000];

int result[10000];
bool visited[10000];
int ffm, fto;
int total = 0;

queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> fm >> to >> ck;

		pre[to - 1]++;
		post[fm - 1].push_back({ to - 1, ck });
		rvrs[to - 1].push_back({ fm - 1, ck });
	}

	cin >> ffm >> fto;

	Q.push(ffm - 1);

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		for (int i = 0; i < post[idx].size(); i++)
		{
			result[post[idx][i].num] = Max(result[post[idx][i].num], result[idx] + post[idx][i].time);

			if (--pre[post[idx][i].num] == 0)
			{
				Q.push(post[idx][i].num);
			}
		}
	}

	Q.push(fto - 1);

	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();

		for (int i = 0; i < rvrs[idx].size(); i++)
		{
			if (result[idx] - rvrs[idx][i].time == result[rvrs[idx][i].num])
			{
				total++;

				if (visited[rvrs[idx][i].num] == false)
				{
					Q.push(rvrs[idx][i].num);
					visited[rvrs[idx][i].num] = true;
				}
			}
		}
	}

	cout << result[fto - 1] << "\n";
	cout << total << "\n";

	return 0;
}