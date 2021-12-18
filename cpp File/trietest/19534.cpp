#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <deque>

using namespace std;

int N;
int fpnt;
int totalcnt = 0;
int temp;

deque<int> v;
deque<int> copy_v;

int operand[2] = { 0, };
int alphabet[26] = { 0, };

int IsValid()
{
	copy_v.clear();
	for (int i = 0; i < v.size(); i++) {
		copy_v.push_back(v[i]);
	}

	int idx = 1;
	while ( idx < copy_v.size() )
	{
		if (copy_v[idx] == 31)
		{
			if (alphabet[copy_v[idx - 1] - 97] == alphabet[copy_v[idx + 1] - 97])
			{
				copy_v[idx - 1] = 1000;
				copy_v.erase(copy_v.begin() + idx, copy_v.begin() + idx + 2);
			}
			else
			{
				copy_v[idx - 1] = 1001;
				copy_v.erase(copy_v.begin() + idx, copy_v.begin() + idx + 2);
			}
		}else idx += 2;
	}

	idx = 1;
	while ( idx < copy_v.size() )
	{
		if (copy_v[idx] == 32)
		{
			if (copy_v[idx - 1] == 1000)
			{
				temp = 1000;
			}
			else
			{
				temp = 1001;
			}
			idx += 2;
		}else
		{
			if (temp == 1000) return alphabet[copy_v[idx - 1] - 97];
			else return alphabet[copy_v[idx + 1] - 97];
		}
	}
}

void BFS(int cnt)
{
	if (cnt == N)
	{
		if (IsValid() == 0)
		{
			totalcnt++;	
		}

		return;
	}

	for (int i = 0; i < 2; i++)
	{
		alphabet[cnt] = i;
		BFS(cnt + 1);
	}
}

void Input()
{
	cin >> N;
	fpnt = pow(2, N);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '=')
		{
			i++;
			v.push_back(31);
			continue;
		}
		else if (s[i] == '?')
		{
			operand[1] += 1;
			v.push_back(32);
			continue;
		}
		else if (s[i] == ':')
		{
			v.push_back(33);
			continue;
		}
		else
		{
			v.push_back(s[i]);
			continue;
		}
	}
}

void Solve()
{
	Input();
	BFS(0);
	cout << totalcnt << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}