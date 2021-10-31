#include <vector>
#include <algorithm>

using namespace std;

int N, MAP[301][301];
int maxh = 0;
int l, r, mid;

long long cal(long long gap, int P, int Q)
{
	long long result = 0;

	if (gap < 0)
	{
		result = (long long)(gap * P * (-1));
	}
	else
	{
		result = (long long)(gap * Q);
	}

	return result;
}

long long solve(int idx, int P, int Q)
{
	long long sum_l = 0;
	long long sum_mid = 0;
	long long sum_r = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long temp = (long long)(MAP[i][j] - idx);

			if (idx == 0)
			{
				sum_l += cal(temp, P, Q);
				sum_mid += cal(temp, P, Q);
				sum_r += cal(temp - 1, P, Q);
			}
			else if (idx == maxh)
			{
				sum_l += cal(temp + 1, P, Q);
				sum_mid += cal(temp, P, Q);
				sum_r += cal(temp, P, Q);
			}
			else
			{
				sum_l += cal(temp + 1, P, Q);
				sum_mid += cal(temp, P, Q);
				sum_r += cal(temp - 1, P, Q);
			}
		}
	}

	if (sum_l >= sum_mid && sum_mid <= sum_r) return sum_mid;
	if (sum_l >= sum_mid && sum_mid >= sum_r) return -1;
	if (sum_l <= sum_mid && sum_mid <= sum_r) return -2;
}

long long solution(vector<vector<int>> land, int P, int Q)
{
	long long answer = -1;

	N = land.size();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAP[i][j] = land[i][j];
			maxh = max(maxh, MAP[i][j]);
		}
	}

	l = 0;
	r = maxh;

	while (l <= r)
	{
		mid = (l + r) / 2;

		long long result = solve(mid, P, Q);

		if (result == -1) // 감소
		{
			l = mid + 1;
		}
		else if (result == -2) // 증가
		{
			r = mid - 1;
		}
		else
		{
			answer = result;
			break;
		}
	}

	return answer;
}