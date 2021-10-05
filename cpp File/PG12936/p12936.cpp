#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ll ftrl[21];
bool visited[21];

vector<int> solution(int n, long long k)
{
	vector<int> answer(n);

	ftrl[0] = 1;

	for (int i = 1; i <= 20; i++)
	{
		ftrl[i] = ftrl[i - 1] * i;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[j]) continue;

			if (k > ftrl[n - i - 1])
			{
				k -= ftrl[n - i - 1];
			}
			else
			{
				visited[j] = true;
				answer[i] = j;
				break;
			}
		}
	}

	return answer;
}