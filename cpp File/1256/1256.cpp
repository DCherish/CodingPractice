#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int N, M, K;
int DP[101][101];

bool state = true;
string ans;

int word_able(int a, int z)
{
	if (a == 0 || z == 0) return 1;

	int result = DP[a][z];

	if (result != -1) return result;

	result = min(word_able(a - 1, z) + word_able(a, z - 1), 1000000000 + 1);

	DP[a][z] = result;

	return result;
}

void word_make(int a, int z, int skip)
{
	if (a == 0)
	{
		for (int i = 0; i < z; i++)
		{
			ans += 'z';
		}

		return;
	}

	if (z == 0)
	{
		for (int i = 0; i < a; i++)
		{
			ans += 'a';
		}

		return;
	}

	int idx = word_able(a - 1, z);

	if (skip < idx)
	{
		ans += 'a';
		word_make(a - 1, z, skip);
	}
	else
	{
		ans += 'z';
		word_make(a, z - 1, skip - idx);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	memset(DP, -1, sizeof(DP));

	if (K > word_able(N, M))
	{
		state = false;
	}
	else
	{
		word_make(N, M, K - 1);
	}

	if (state == false)
	{
		cout << "-1\n";
	}
	else
	{
		cout << ans << "\n";
	}

	return 0;
}