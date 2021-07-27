#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int T, a, b, temp;

vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;

		if (a == 1 || a == 5 || a == 6)
		{
			answer.push_back(a);
			continue;
		}
		else if (a == 4 || a == 9)
		{
			b %= 2;

			if (b == 0) b = 2;
		}
		else
		{
			b %= 4;

			if (b == 0) b = 4;
		}

		temp = pow(a, b);

		temp %= 10;

		if (temp == 0)
		{
			answer.push_back(10);
		}
		else answer.push_back(temp);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}