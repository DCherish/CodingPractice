#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie)
{
	int answer = 0;

	for (int i = 0; i < cookie.size() - 1; i++)
	{
		int l_sum = cookie[i];
		int r_sum = cookie[i + 1];

		int l_idx = i;
		int r_idx = i + 1;

		while (true)
		{
			if (l_sum == r_sum) answer = max(answer, l_sum);

			if (l_sum > r_sum)
			{
				if (r_idx + 1 == cookie.size()) break;

				r_sum += cookie[r_idx + 1];
				r_idx++;
			}
			else
			{
				if (l_idx - 1 < 0) break;

				l_sum += cookie[l_idx - 1];
				l_idx--;
			}
		}
	}

	return answer;
}