#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, cmd;

ll ftrl[21];
bool visited[21];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	ftrl[0] = 1;

	for (int i = 1; i <= 20; i++)
	{
		ftrl[i] = ftrl[i - 1] * i;
	}

	cin >> cmd;

	if (cmd == 1)
	{
		ll k;

		vector<int> vec(N);

		cin >> k;

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visited[j] == true) continue;

				if (k > ftrl[N - i - 1])
				{
					k -= ftrl[N - i - 1];
				}
				else
				{
					visited[j] = true;
					vec[i] = j;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			cout << vec[i] << " ";
		}
	}
	else
	{
		ll result = 1;

		vector<int> vec(N);

		for (int i = 0; i < N; i++)
		{
			cin >> vec[i];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < vec[i]; j++)
			{
				if (visited[j] == true) continue;

				result += ftrl[N - i - 1];
			}

			visited[vec[i]] = true;
		}

		cout << result;
	}

	cout << "\n";

	return 0;
}