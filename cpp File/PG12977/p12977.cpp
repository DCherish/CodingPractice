#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int answer = 0;

bool visited[1001];
bool prime[3001];

void DFS(int depth, int idx, vector<int> nums)
{
	if (depth == 3)
	{
		int cnt = 0;
		int sum = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[nums[i]] == true)
			{
				sum += nums[i];
				cnt++;
			}

			if (cnt == 3) break;
		}

		if (prime[sum] == true) answer++;

		return;
	}

	for (int i = idx; i < nums.size(); i++)
	{
		visited[nums[i]] = true;
		DFS(depth + 1, i + 1, nums);
		visited[nums[i]] = false;
	}
}

void pre_setting()
{
	memset(visited, false, sizeof(visited));
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(3000); i++)
	{
		if (prime[i] == false) continue;

		for (int j = i * i; j <= 3000; j += i)
		{
			prime[j] = false;
		}
	}
}

int solution(vector<int> nums)
{
	pre_setting();

	DFS(0, 0, nums);

	return answer;
}