#include <iostream>
#include <cmath> // for sqrt(x)

using namespace std;

int N, num;
int cnt;
int result = 0;

void isPrimeNumber(int idx)
{
	if (idx <= 1) return;

	int rt = sqrt(idx);

	for (int i = 2; i <= rt; i++)
	{
		if (idx % i == 0)
		{
			return;
		}
	}

	result++;
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

		isPrimeNumber(num);
	}

	cout << result << "\n";

	return 0;
}