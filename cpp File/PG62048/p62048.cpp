#include <algorithm>

using namespace std;
typedef long long ll;

int gcd(int w, int h)
{
	if (w < h) swap(w, h);

	while (true)
	{
		int temp = w % h;

		if (temp == 0) return h;
		else
		{
			w = h;
			h = temp;
		}
	}
}

long long solution(int w, int h)
{
	ll answer = (ll)w * (ll)h;

	answer -= (ll)w;
	answer -= (ll)h;

	answer += (ll)gcd(w, h);

	return answer;
}