#include <iostream>
#include <vector>

using namespace std;

int A, B;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> A >> B)
	{
		answer.push_back(A + B);
	}
	// while 안에 이렇게 넣을 수 있다.

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}