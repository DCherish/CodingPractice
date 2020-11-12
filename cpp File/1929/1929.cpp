#include <iostream>

using namespace std;

int N, M;
bool arr[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	arr[1] = true;

	for (int i = 2; i <= M; i++)
	{
		if (arr[i] == false)
		{
			for (int j = i + i; j <= M; j += i)
			{
				arr[j] = true;
			}
		}
	}

	for (int i = N; i <= M; i++)
	{
		if (arr[i] == false)
		{
			cout << i << "\n";
		}
	}

	return 0;
}