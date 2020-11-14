#include <iostream>
#include <vector>

using namespace std;

int T;
int H, W, N;
int yy, xx;

vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;

		yy = N % H;
		xx = N / H;

		if (yy == 0)
		{
			yy = H;
		}
		else
		{
			xx += 1;
		}

		answer.push_back(yy * 100 + xx);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}