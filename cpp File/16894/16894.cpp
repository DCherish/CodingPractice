#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll N, cnt, temp;

void check()
{
	temp = N;

	for (ll i = 2; i <= sqrt(temp) && cnt < 2; i++)
	{
		while (temp % i == 0)
		{
			temp /= i;
			cnt++;
		}
	}

	if (temp > 1) cnt++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	check();

	if (cnt == 2) cout << "cubelover\n";
	else cout << "koosaga\n";

	return 0;
}