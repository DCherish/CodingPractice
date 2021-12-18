#include <iostream>
#include <algorithm>

using namespace std;

int numinfo[5] = { 0, };

int a;
int N;

int answer;

void Calculate()
{
	while (numinfo[3] != 0)
	{
		if (numinfo[1] >= 3)
		{
			numinfo[1] -= 3;
			numinfo[4] -= 3;
		}
		else break;
		numinfo[3] -= 1;
	}

	answer = numinfo[4] - numinfo[2];

	if (answer == 0) // 확인
	{
		cout << "YES\n";
		return;
	}
	else if (answer < 0) // 확인
	{
		answer = answer * (-1);

		if (answer % 3 == 0)
		{
			cout << "YES\n";
			return;
		}
		else
		{
			cout << "NO\n";
			return;
		}
	}
	else // 0보다 큰 경우에 !
	{
		if (answer % 3 == 0) // 무조건
		{
			if (numinfo[1] == 0) // 확인
			{
				cout << "YES\n";
				return;
			}
			else if (((numinfo[1] - numinfo[2]) / 2) > (numinfo[4] - numinfo[1]))
			{
				cout << "NO\n";
				return;
			}
			else
			{
				cout << "YES\n";
				return;
			}
		}
		else // 무조건
		{
			cout << "NO\n";
			return;
		}
	}
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;

		if (a == 1)
		{
			numinfo[1] += 1;
			numinfo[4] += 1;
			continue;
		}

		if (a % 3 == 2)
		{
			numinfo[2] += 1;
		}
		else if (a % 3 == 1)
		{
			numinfo[4] += 1;
		}
		else if (a % 3 == 0)
		{
			while (a >= 6)
			{
				numinfo[3] += 1;
				a -= 6;
			}
		}
	}
}

void Solve()
{
	Input();
	Calculate();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int one = 0;
int two = 0;

int N;
int map[100000];
int tmp;
int canuse;
int recent = 0;

int main() {
cin >> N;
for (int i = 0; i < N; i++) {
cin >> tmp;
if (tmp == 1) {
two = two + 1;
tmp = 0;
}
map[i] = tmp;
}

for (int i = 0; i < N; i++) {
if (two != 0) {
canuse = min(map[i] / 2, two);
map[i] = map[i] - 2 * canuse;
two = two - canuse;
}
if (one != 0) {
canuse = min(map[i] / 1, one);
map[i] = map[i] - 1 * canuse;
one = one - canuse;
}
recent = map[i] % 3;
if (recent == 1) two = two + 1;
if (recent == 2) one = one + 1;
}
if (recent == 0 && two == 0 && one == 0) cout << "YES";
else cout << "NO";
}
*/