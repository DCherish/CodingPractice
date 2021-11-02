#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int l, r, mid;

bool check(int num, vector<int>& stones, int& k)
{
	int jmp = 0;

	for (int i = 0; i < stones.size(); i++)
	{
		if (stones[i] - num < 0) jmp += 1;
		else jmp = 0;

		if (jmp >= k) return false;
	}

	return true;
}

int solution(vector<int> stones, int k)
{
	int answer = 0;

	l = 0;
	r = *max_element(stones.begin(), stones.end());

	while (l <= r)
	{
		mid = (l + r) / 2;

		if (check(mid, stones, k))
		{
			answer = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	return answer;
}