#include <string>
#include <vector>

using namespace std;

string num[17] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

int N;
int temp = 0;
int cnt = 1;

string cnvert(int idx)
{
	if (idx < N) return num[idx];

	int front = idx / N;
	int back = idx % N;

	return cnvert(front) + cnvert(back);
}

string solution(int n, int t, int m, int p)
{
	string answer = "";

	N = n;

	while (true)
	{
		string str = cnvert(temp);

		for (int i = 0; i < str.length(); i++)
		{
			if (cnt == p)
			{
				answer += str[i];
			}

			cnt++;

			if (cnt > m) cnt = 1;

			if (answer.length() == t) return answer;
		}

		temp++;
	}
}