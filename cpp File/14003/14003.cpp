#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1000001];
int arridx[1000001];

vector<int> vec;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vec.push_back(arr[0]);
	arridx[0] = 0;

	for (int i = 1; i < N; i++)
	{
		if (vec.back() < arr[i])
		{
			vec.push_back(arr[i]);

			arridx[i] = vec.size() - 1;
		}
		else
		{
			int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();

			vec[idx] = arr[i];

			arridx[i] = idx;
		}
	}

	cout << vec.size() << "\n";

	int find_idx = vec.size() - 1;

	for (int i = N - 1; i >= 0; i--)
	{
		if (arridx[i] == find_idx)
		{
			find_idx--;
			answer.push_back(arr[i]);

			if (find_idx == -1) break;
		}
	}

	for (int i = answer.size() - 1; i >= 0; i--)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";

	return 0;
}