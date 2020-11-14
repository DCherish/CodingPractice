#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, num;
vector<int> vec;
vector<int> answer;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end(), cmp);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		int result = upper_bound(vec.begin(), vec.end(), num) - lower_bound(vec.begin(), vec.end(), num);

		answer.push_back(result);
	}

	// lower_bound ; ã������ key ������ ���ų� ū ���ڰ� �迭 �� ��°�� ó�� �����ϴ��� ?
	// upper_bound : ã������ key ���� �ʰ��ϴ� ���ڰ� �迭 �� ��°�� ó�� �����ϴ��� ?
	// Tip ; �� �� iterator�� ��ȯ�Ǿ� ������ index�� �˰� �ʹٸ� a.begin()�� ���� index ó�� �� �� ����

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";

	return 0;
}