#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int cp1_idx[101];
int cp2_idx[65];

int cp1_money[101];
int cp2_money[65];

int T, a, b, depth;

vector<int> answer;

void cal()
{
	depth = 1;

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cp1_idx[depth] = i;
			depth++;
		}
	}

	depth = 1;

	for (int i = 1; i <= 5; i++)
	{
		int pow_i = pow(2, i - 1);

		for (int j = 1; j <= pow_i; j++)
		{
			cp2_idx[depth] = i;
			depth++;
		}
	}

	cp1_money[1] = 5000000;
	cp1_money[2] = 3000000;
	cp1_money[3] = 2000000;
	cp1_money[4] = 500000;
	cp1_money[5] = 300000;
	cp1_money[6] = 100000;

	cp2_money[1] = 5120000;
	cp2_money[2] = 2560000;
	cp2_money[3] = 1280000;
	cp2_money[4] = 640000;
	cp2_money[5] = 320000;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cal();

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;

		int sum = cp1_money[cp1_idx[a]] + cp2_money[cp2_idx[b]];

		answer.push_back(sum);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}