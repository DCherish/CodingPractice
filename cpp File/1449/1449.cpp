#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001

using namespace std;

int N, L;
int ans = 0;

int pipe[MAX];
bool taped[MAX];

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		cin >> pipe[i];
	}

	sort(pipe, pipe + N, cmp); // ¹è¿­ sort

	for (int i = 0; i < N; i++)
	{
		if (taped[pipe[i]] == false)
		{
			for (int j = pipe[i]; j < min(pipe[i] + L, MAX); j++)
			{
				taped[j] = true;
			}

			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}