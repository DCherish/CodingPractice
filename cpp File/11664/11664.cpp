#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct pnt
{
	double x;
	double y;
	double z;
};

pnt a, b, c;

double low = 0;
double high = 100;

double p, q;
double answer = 30000;

pnt makedot(double idx)
{
	pnt result;

	result.x = a.x + (b.x - a.x) * (idx / 100);
	result.y = a.y + (b.y - a.y) * (idx / 100);
	result.z = a.z + (b.z - a.z) * (idx / 100);

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a.x >> a.y >> a.z;
	cin >> b.x >> b.y >> b.z;
	cin >> c.x >> c.y >> c.z;

	while (high - low >= 1e-6)
	{
		p = (2 * low + high) / 3;
		q = (low + 2 * high) / 3;

		pnt pdot = makedot(p);
		pnt qdot = makedot(q);

		double plen = pow(pdot.x - c.x, 2) + pow(pdot.y - c.y, 2) + pow(pdot.z - c.z, 2);
		double qlen = pow(qdot.x - c.x, 2) + pow(qdot.y - c.y, 2) + pow(qdot.z - c.z, 2);

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