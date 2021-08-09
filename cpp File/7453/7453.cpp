#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, a, b, c, d;

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;

vector<int> AB;
vector<int> CD;

ll cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;

		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end(), less<int>());
	sort(CD.begin(), CD.end(), less<int>());

	for (int i = 0; i < AB.size(); i++)
	{
		ll l = lower_bound(CD.begin(), CD.end(), -1 * AB[i]) - CD.begin();
		ll r = upper_bound(CD.begin(), CD.end(), -1 * AB[i]) - CD.begin();

		cnt += r - l;
	}

	cout << cnt << "\n";

	return 0;
}