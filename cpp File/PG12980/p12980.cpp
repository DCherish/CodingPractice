#include <vector>

using namespace std;

int solution(int n)
{
	int ans = 1;

	int cnt = 0;

	while (n != 1)
	{
		if (n % 2 != 0)
		{
			n -= 1;
			cnt++;
		}
		else
		{
			n /= 2;
		}
	}

	if (cnt > 0) ans += cnt;

	return ans;
}