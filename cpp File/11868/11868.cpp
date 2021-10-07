#include <iostream>

using namespace std;

int N, temp, num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;

		temp = (temp ^ num);
	}

	if (temp == 0) cout << "cubelover\n";
	else cout << "koosaga\n";

	return 0;
}