#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, ans;
bool p_check[4000001];

vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	memset(p_check, true, (N + 1) * sizeof(bool));
	//memset(p_check, true, sizeof(p_check));

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (p_check[i] == false) continue;

		for (int j = i + i; j <= N; j = j + i)
		{
			p_check[j] = false;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (p_check[i] == true)
		{
			vec.push_back(i);
		}
	}

	int start = 0;
	int end = 0;
	long long sum = 0;

	while (true)
	{
		if (sum >= N)
		{
			sum -= vec[start];
			start++;
		}
		else if (end == vec.size()) break;
		else
		{
			sum += vec[end];
			end++;
		}

		if (sum == N) ans++;
	}

	cout << ans << "\n";

	return 0;
}