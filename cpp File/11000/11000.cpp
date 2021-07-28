#include <iostream>
#include <queue>

using namespace std;

struct info
{
	int start;
	int end;
};

class cmp_s
{
public:
	bool operator()(info a, info b)
	{
		if (a.start == b.start)
		{
			return a.end > b.end;
		}
		else return a.start > b.start;
	}
};

class cmp_e
{
public:
	bool operator()(info a, info b)
	{
		if (a.end == b.end)
		{
			return a.start > b.start;
		}
		else return a.end > b.end;
	}
};

int N, s, t, cnt;

priority_queue<info, vector<info>, cmp_s> PQ_S;
priority_queue<info, vector<info>, cmp_e> PQ_E;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> t;

		PQ_S.push({ s, t });
	}

	int ts = PQ_S.top().start;
	int te = PQ_S.top().end;
	PQ_S.pop();

	cnt = 1;

	PQ_E.push({ ts, te });

	while (!PQ_S.empty())
	{
		int ns = PQ_S.top().start;
		int ne = PQ_S.top().end;
		PQ_S.pop();

		if (PQ_E.top().end > ns)
		{
			cnt++;
			PQ_E.push({ ns, ne });
		}
		else
		{
			PQ_E.pop();
			PQ_E.push({ ns, ne });
		}
	}

	cout << cnt << "\n";

	return 0;
}