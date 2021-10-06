#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct pnt
{
	double x;
	double y;
};

pnt a, b, c, d;

double low = 0;
double high = 100;

double p, q;
double answer = 15000;

pnt minho(double idx)
{
	pnt result;

	result.x = a.x + (b.x - a.x) * (idx / 100);
	result.y = a.y + (b.y - a.y) * (idx / 100);

	return result;
}

pnt kangho(double idx)
{
	pnt result;

	result.x = c.x + (d.x - c.x) * (idx / 100);
	result.y = c.y + (d.y - c.y) * (idx / 100);

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	while (high - low >= 1e-6)
	{
		p = (2 * low + high) / 3;
		q = (low + 2 * high) / 3;

		pnt mp = minho(p);
		pnt kp = kangho(p);

		pnt mq = minho(q);
		pnt kq = kangho(q);

		double plen = pow(mp.x - kp.x, 2) + pow(mp.y - kp.y, 2);
		double qlen = pow(mq.x - kq.x, 2) + pow(mq.y - kq.y, 2);

		plen = sqrt(plen);
		qlen = sqrt(qlen);

		answer = min(answer, min(plen, qlen));

		if (plen >= qlen) low = p;
		else high = q;
	}

	cout << fixed;
	cout.precision(10);

	cout << answer << "\n";

	return 0;
}