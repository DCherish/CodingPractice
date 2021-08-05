#include <iostream>
#include <vector>

using namespace std;

struct info
{
	int N;
	int cnt;
};

int P, N, M, cnt, a, b;

vector<info> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> P;

	for (int i = 0; i < P; i++)
	{
		cin >> N >> M;

		cnt = 0;
		a = 1;
		b = 1;

		while (true)
		{
			int temp = (a + b) % M;
			a = b;
			b = temp;
			cnt++;

			if (a == 1 && b == 1) break;
		}

		vec.push_back({ N, cnt });
	}

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].N << " " << vec[i].cnt << "\n";
	}

	return 0;
}