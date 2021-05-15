#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct info
{
	string str;
	int cnt;
};

int num, result;
string start_str, end_str;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

map<string, int> map_info;

queue<info> Q;

int BFS()
{
	Q.push({ start_str, 0 });

	while (!Q.empty())
	{
		string temp_str = Q.front().str;
		int temp_cnt = Q.front().cnt;
		Q.pop();

		if (temp_str.compare(end_str) == 0) return temp_cnt;

		int zero_idx = temp_str.find("0");

		int zero_x = zero_idx / 3;
		int zero_y = zero_idx % 3;

		for (int i = 0; i < 4; i++)
		{
			int nx = zero_x + dx[i];
			int ny = zero_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;

			string next_str = temp_str;
			swap(next_str[zero_x * 3 + zero_y], next_str[nx * 3 + ny]);

			if (map_info.count(next_str) == 0)
			{
				map_info[next_str]++;
				Q.push({ next_str, temp_cnt + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	start_str = "";
	end_str = "123456780";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num;

			start_str += to_string(num);
		}
	}

	result = BFS();

	cout << result << "\n";

	return 0;
}