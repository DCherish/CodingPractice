#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end(), less<int>());
	sort(B.begin(), B.end(), less<int>());

	int aidx = A.size() - 1;
	int bidx = B.size() - 1;

	while (true)
	{
		if (aidx < 0) break;

		if (A[aidx] < B[bidx])
		{
			answer++;
			bidx--;
		}

		aidx--;
	}

	return answer;
}