#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class info
{
public:
	int a;
	int b;
};

class g_cmp
{
public:
	bool operator()(info i1, info i2)
	{
		return i1.a < i2.a;
	}
};

class l_cmp
{
public:
	bool operator()(info i1, info i2)
	{
		return i1.a > i2.a;
	}
};

int T, k;

char c;
int num;
bool visited[1000000];

vector<string> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		priority_queue<info, vector<info>, g_cmp> PQMAX;
		priority_queue<info, vector<info>, l_cmp> PQMIN;

		cin >> k;

		for (int j = 0; j < k; j++)
		{
			cin >> c;
			cin >> num;

			if (c == 'I')
			{
				PQMAX.push({ num, j });
				PQMIN.push({ num, j });
				visited[j] = true;
			}
			else
			{
				if (num == 1)
				{
					while (!PQMAX.empty() && !visited[PQMAX.top().b])
					{
						PQMAX.pop();
					}

					if (!PQMAX.empty())
					{
						visited[PQMAX.top().b] = false;
						PQMAX.pop();
					}
				}
				else
				{
					while (!PQMIN.empty() && !visited[PQMIN.top().b])
					{
						PQMIN.pop();
					}

					if (!PQMIN.empty())
					{
						visited[PQMIN.top().b] = false;
						PQMIN.pop();
					}
				}
			}
		}

		while (!PQMAX.empty() && !visited[PQMAX.top().b])
		{
			PQMAX.pop();
		}

		while (!PQMIN.empty() && !visited[PQMIN.top().b])
		{
			PQMIN.pop();
		}

		if (PQMAX.empty() && PQMIN.empty())
		{
			answer.push_back("EMPTY");
		}
		else
		{
			string s1 = to_string(PQMAX.top().a);
			string s2 = to_string(PQMIN.top().a);

			answer.push_back(s1 + " " + s2);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}