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

	// lower_bound ; 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에 처음 등장하는지 ?
	// upper_bound : 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에 처음 등장하는지 ?
	// Tip ; 둘 다 iterator로 반환되어 각각의 index를 알고 싶다면 a.begin()을 빼면 index 처럼 알 수 있음

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";

	return 0;
}