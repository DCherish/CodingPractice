#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++)
	{
		cin >> num;

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	do
	{
		vector<int> temp;
		int sum = 0;

		for (int i = 0; i < 7; i++)
		{
			temp.push_back(vec[i]);
			sum += vec[i];
		}

		if (sum == 100)
		{
			for (int i = 0; i < temp.size(); i++)
			{
				cout << temp[i] << "\n";
			}

			break;
		}

	} while (next_permutation(vec.begin(), vec.end()));

	return 0;
}