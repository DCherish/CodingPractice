#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getNs(int N, int k)
{
	int result = 0;

	for (int i = 1; i <= k; i++)
	{
		result *= 10;
		result += N;
	}

	return result;
}

int solution(int N, int number)
{
	int answer = -1;

	if (N == number) answer = 1;
	else
	{
		vector<unordered_set<int>> DP(9);

		for (int k = 1; k <= 8; k++)
		{
			DP[k].insert(getNs(N, k));

			for (int i = 1; i < k; i++)
			{
				for (int j = 1; j < k; j++)
				{
					if (i + j != k) continue;

					for (const auto& a : DP[i])
					{
						for (const auto& b : DP[j])
						{
							DP[k].insert(a + b);

							if (a - b > 0) DP[k].insert(a - b);

							DP[k].insert(a * b);

							if (a / b > 0) DP[k].insert(a / b);
						}
					}
				}
			}

			//if (DP[k].find(number) != DP[k].end())
			if (DP[k].count(number) != 0)
			{
				answer = k;
				break;
			}
		}
	}

	return answer;
}