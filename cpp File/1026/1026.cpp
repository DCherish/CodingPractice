#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int num;
	int idx;
};

int N, num;

vector<int> A;
int B[50];

vector<info> vec;

int ans = 0;

bool cmp(info a, info b)
{
	return a.num < b.num;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];

		vec.push_back({ B[i], i });
	}

	sort(A.begin(), A.end(), greater<int>());
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		ans += A[i] * B[vec[i].idx];
	}

	cout << ans << "\n";

	return 0;
}