#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n;

int DP_0[41];
int DP_1[41];

vector<int> answerzero;
vector<int> answerone;

void fibonacci()
{
	DP_0[0] = 1;
	DP_0[1] = 0;
	DP_1[0] = 0;
	DP_1[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		DP_0[i] = DP_0[i - 1] + DP_0[i - 2];
		DP_1[i] = DP_1[i - 1] + DP_1[i - 2];
	}

	answerzero.push_back(DP_0[n]);
	answerone.push_back(DP_1[n]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		fibonacci();
	}

	for (int i = 0; i < answerzero.size(); i++)
	{
		cout << answerzero[i] << " " << answerone[i] << "\n";
	}
}