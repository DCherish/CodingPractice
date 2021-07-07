#include <iostream>
#include <deque>

using namespace std;

struct info
{
	int cnt;
	bool robot;
};

int stage = 0;
int N, K;
int cnt[200];

deque<info> belt;

void rot()
{
	info temp = belt.back();
	belt.pop_back();

	belt.push_front(temp);

	if (belt[N - 1].robot == true) belt[N - 1].robot = false;

	for (int i = N - 2; i >= 0; i--)
	{
		if (belt[i].robot == false) continue;
		else
		{
			if (belt[i + 1].cnt >= 1 && belt[i + 1].robot == false)
			{
				belt[i + 1].cnt--;
				belt[i].robot = false;

				if (i == N - 2) continue;
				belt[i + 1].robot = true;
			}
		}
	}
}

void put_robot()
{
	if (belt[0].robot == false && belt[0].cnt >= 1)
	{
		belt[0].cnt--;
		belt[0].robot = true;
	}
}

bool check_cnt()
{
	int temp_cnt = 0;

	for (int i = 0; i < 2 * N; i++)
	{
		if (belt[i].cnt == 0) temp_cnt++;
	}

	if (temp_cnt >= K) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < 2 * N; i++)
	{
		cin >> cnt[i];

		belt.push_back({ cnt[i], false });
	}

	while (true)
	{
		stage++;

		rot();

		put_robot();

		if (check_cnt() == true) break;
	}

	cout << stage << "\n";

	return 0;
}