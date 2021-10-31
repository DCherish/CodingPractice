#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int prev = 1;

	for (int idx : stations)
	{
		int len = (idx - w) - prev;
		int cnt = (int)ceil((double)len / (double)(2 * w + 1));

		answer += cnt;

		prev = idx + w + 1;
	}

	answer += (int)ceil((double)(n - prev + 1) / (double)(2 * w + 1));

	return answer;
}