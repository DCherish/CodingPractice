#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

string N;
int K, M;
int result;

void BFS()
{
	queue<string> Q;
	Q.push(N);

	int ck = 0;
	int ans = 0;

	while (!Q.empty() && ck < K)
	{
		int sz = Q.size();
		set<string> visited;

		for (int s = 0; s < sz; s++)
		{
			string str = Q.front();
			Q.pop();

			for (int i = 0; i < M - 1; i++)
			{
				for (int j = i + 1; j < M; j++)
				{
					if (i == 0 && str[j] == '0') continue;

					swap(str[i], str[j]);

					if (visited.find(str) == visited.end())
					{
						if (ck == K - 1 && ans < stoi(str))
						{
							ans = stoi(str);
						}

						Q.push(str);
						visited.insert(str);
					}

					swap(str[i], str[j]);
				}
			}
		}
		ck++;
	}

	if (ck != K) result = -1;
	else result = ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	M = N.length();

	if (M == 1 || (M == 2 && N[1] == '0'))
	{
		result = -1;
	}
	else
	{
		BFS();
	}

	cout << result << "\n";

	return 0;
}