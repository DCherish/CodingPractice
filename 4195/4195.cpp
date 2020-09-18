#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int t, F;
int index;
int z1, z2;
string s1, s2;

vector<int> answer;

int number[200001];
int parent[200001];

int Find(int k)
{
	if (parent[k] == k) return k;
	else return parent[k] = Find(parent[k]);
}

void Function(int a, int b)
{
	int fa = Find(a);
	int fb = Find(b);

	if (fa < fb) // 작은 노드 기준으로 부모 설정
	{
		parent[fb] = fa; // 부모노드 변경

		number[fa] = number[fa] + number[fb]; // 부모 밑 자식 수 변경
		number[fb] = 1;

		answer.push_back(number[fa]); // 정답 배열에 저장
	}
	else if (fa > fb)
	{
		parent[fa] = fb; // 부모노드 변경

		number[fb] = number[fb] + number[fa]; // 부모 밑 자식 수 변경
		number[fa] = 1;

		answer.push_back(number[fb]);
	}else
	{
		answer.push_back(number[fa]);
	}
}

void init(int k) // 초기화
{
	for (int i = 1; i <= 2 * k; i++)
	{
		parent[i] = i;
		number[i] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> F;

		init(F);

		map<string, int> fr;
		index = 1;

		for (int j = 0; j < F; j++)
		{
			cin >> s1 >> s2;

			if (fr.count(s1) == 0) // 번호 할당
			{
				fr[s1] = index++;
			}

			z1 = fr[s1];

			if (fr.count(s2) == 0) // 번호 할당
			{
				fr[s2] = index++;
			}

			z2 = fr[s2];

			Function(z1, z2);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n"; // 답 출력
	}

	return 0;
}
