#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int height[1000001];
int width[1000001];

vector<vector<int>> temp;

bool cmp(vector<int> v1, vector<int> v2)
{
	if (v1[1] == v2[1]) return v1[0] < v2[0];
	else return v1[1] < v2[1];
}

bool cmp2(vector<int> v1, vector<int> v2)
{
	return v1[4] < v2[4];
}

void down()
{
	for (int i = 0; i < temp.size(); i++)
	{
		int c1 = temp[i][0];
		int r1 = temp[i][1];
		int c2 = temp[i][2];
		int r2 = temp[i][3];
		
		int h = r2 - r1;

		int max_h = 0;

		for (int j = c1; j < c2; j++)
		{
			max_h = max(max_h, height[j]);
		}

		temp[i][1] = max_h;
		temp[i][3] = h + max_h;

		for (int j = c1; j < c2; j++)
		{
			height[j] = temp[i][3];
		}
	}
}

void left()
{
	for (int i = 0; i < temp.size(); i++)
	{
		int c1 = temp[i][0];
		int r1 = temp[i][1];
		int c2 = temp[i][2];
		int r2 = temp[i][3];
		
		int w = c2 - c1;

		int max_w = 0;

		for (int j = r1; j < r2; j++)
		{
			max_w = max(max_w, width[j]);
		}

		temp[i][0] = max_w;
		temp[i][2] = w + max_w;

		for (int j = r1; j < r2; j++)
		{
			width[j] = temp[i][2];
		}
	}
}


vector<string> solution(vector<vector<int>> rectangles)
{
	vector<string> ans;

	for (int i = 0; i < rectangles.size(); i++)
	{
		vector<int> tmp = rectangles[i];
		tmp.push_back(i);

		temp.push_back(tmp);
	}

	sort(temp.begin(), temp.end(), cmp);
	down();

	sort(temp.begin(), temp.end(), cmp);
	left();

	sort(temp.begin(), temp.end(), cmp2);

	for (int i = 0; i < rectangles.size(); i++)
	{
		string s = "";
		s = to_string(temp[i][0]) + " " + to_string(temp[i][1]) + " " + to_string(temp[i][2]) + " " + to_string(temp[i][3]);
		ans.push_back(s);
		cout << s << "\n";
	}

	return ans;
}

int main()
{
	vector<vector<int>> v;

	v.push_back({ 0, 2, 1, 3 });
	v.push_back({ 1, 2, 2, 5 });
	v.push_back({ 3, 3, 4, 4 });
	v.push_back({ 4, 1, 6, 3 });
	v.push_back({ 1, 6, 5, 7 });
	v.push_back({ 5, 5, 7, 6 });
	v.push_back({ 5, 8, 6, 10 });
	
	solution(v);

	return 0;
}