#include <iostream>

using namespace std;

int N, K;
int order[100];
int plug[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> order[i];
	}

	int result = 0;

	for (int i = 0; i < K; i++)
	{
		bool plug_in = false;

		for (int j = 0; j < N; j++)
		{
			if (plug[j] == order[i])
			{
				plug_in = true;
				break;
			}
		}

		if (plug_in == true) continue;

		for (int j = 0; j < N; j++)
		{
			if (plug[j] == false)
			{
				plug[j] = order[i];
				plug_in = true;
				break;
			}
		}

		if (plug_in == true) continue;

		int idx, d_idx = -1;

		for (int j = 0; j < N; j++)
		{
			int l_idx = 0;

			for (int m = i + 1; m < K; m++)
			{
				if (plug[j] == order[m]) break;
				l_idx++;
			}

			if (l_idx > d_idx)
			{
				idx = j;
				d_idx = l_idx;
			}
		}

		result++;

		plug[idx] = order[i];
	}

	cout << result << "\n";

	return 0;
}