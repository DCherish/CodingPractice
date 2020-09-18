#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long arr[101];
int T, N;
vector<long long> v;

void DP()
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	
	for (int i = 6; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	v.push_back(arr[N]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		DP();
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}