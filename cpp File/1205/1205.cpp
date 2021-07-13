#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, S, P;
int score[50];

int lev = 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S >> P;

	memset(score, -1, sizeof(score));

	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}

	if (score[P - 1] >= S)
	{
		cout << -1 << "\n";
	}
	else
	{
		for (int i = 0; i < P; i++)
		{
			if (score[i] > S) lev++;
			else if (score[i] == S) continue;
			else break;
		}

		cout << lev << "\n";
	}

	return 0;
}