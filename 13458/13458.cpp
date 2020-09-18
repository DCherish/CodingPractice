#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C;
int N;

int room[1000000];
long long cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		room[i] = A;
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		room[i] = room[i] - B;
		cnt++;
	}

	for (int i = 0; i < N; i++)
	{
		if (room[i] > 0)
		{
			int dv_cnt = room[i] / C;
			int rv_cnt = room[i] % C;
			
			if (rv_cnt == 0) cnt = cnt + dv_cnt;
			else cnt = cnt + dv_cnt + 1;
		}
	}

	cout << cnt << "\n";

	return 0;
}