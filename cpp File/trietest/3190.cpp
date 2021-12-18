#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class info
{
public:
	int num;
	char dir;
};

int N, K;
int Row, Col;
int L;
int X;
char C;

int cnt = 0;

int board[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

vector<info> v;

void function()
{
	int idx = 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> Row >> Col;
		board[Row][Col] = 1;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		v.push_back({X, C});
	}

	function();

	cout << cnt << "\n";

	return 0;
}