#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
	vector<string> answer;

	for (int i = 0; i < n; i++)
	{
		int num1 = arr1[i];
		int num2 = arr2[i];

		string result = "";

		for (int j = n - 1; j >= 0; j--)
		{
			if ((num1 & (1 << j)) == 0 && (num2 & (1 << j)) == 0) result += " ";
			else result += "#";
		}

		answer.push_back(result);
	}

	return answer;
}