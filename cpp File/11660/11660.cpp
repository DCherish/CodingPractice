#include <iostream>
#include <vector>

using namespace std;

int N, M;
int MAP[1025][1025];
int DP[1025][1025];

vector<int> ans;

void cal()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + MAP[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	cal();

	for (int i = 0; i < M; i++)
	{
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		int result = DP[c][d] - DP[a - 1][d] - DP[c][b - 1] + DP[a - 1][b - 1];

		ans.push_back(result);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}