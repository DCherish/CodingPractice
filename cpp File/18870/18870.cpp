#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class info
{
public:
	int x;
	int y;
};

int N, x, tempidx, tempcnt;
vector<info> vec;
int cnt[1000000];

bool cmp(info a, info b)
{
	return a.x < b.x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		vec.push_back({ x, i });
	}

	sort(vec.begin(), vec.end(), cmp);

	tempidx = vec[0].x;
	tempcnt = 0;
	cnt[vec[0].y] = 0;

	for (int i = 1; i < N; i++)
	{
		if (vec[i].x == tempidx)
		{
			cnt[vec[i].y] = tempcnt;
		}
		else
		{
			cnt[vec[i].y] = tempcnt + 1;
			tempidx = vec[i].x;

			tempcnt++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << cnt[i] << " ";
	}

	cout << "\n";

	// �ð����� TIP
	// sort(a, b) // �⺻ �������� 12345
	// sort(a, b, less<int>()) // �������� 12345
	// sort(a, b, greater<int>()) // �������� 54321
	// sort(a, b, cmp) // cmp ����

	// ����
	// sort index �ٷ�� ��
	// pair lower_bound ��

	return 0;
}