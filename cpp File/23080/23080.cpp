#include <iostream>
#include <string>

using namespace std;

int K;
string S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K;
	cin >> S;

	string answer = "";

	for (int i = 0; i < S.length();)
	{
		answer += S[i];
		i += K;
	}

	cout << answer << "\n";

	return 0;
}