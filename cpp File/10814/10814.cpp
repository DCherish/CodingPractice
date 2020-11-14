#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class info
{
public:
	int age;
	string name;
	int joinidx;
};

int N;
vector<info> vec;

bool cmp(info i1, info i2)
{
	if (i1.age == i2.age)
	{
		return i1.joinidx < i2.joinidx;
	}
	else return i1.age < i2.age;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		info temp;

		cin >> temp.age;
		cin.ignore();

		getline(cin, temp.name);

		temp.joinidx = i + 1;

		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].age << " " << vec[i].name << "\n";
	}

	return 0;
}