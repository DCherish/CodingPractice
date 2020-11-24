#include <iostream>

using namespace std;

int N, num;
int visited[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;

		for (int j = 0; j < N; j++)
		{
			if (num == 0 && visited[j] == 0)
			{
				visited[j] = i;
				break;
			}
			else if (visited[j] == 0)
			{
				num--;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << visited[i] << " ";
	}

	cout << "\n";

	return 0;
}