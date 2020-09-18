#include <iostream>
#include <algorithm>
#define Min(a, b) (a > b ? b : a)

using namespace std;

int N;
int R, G, B;
int temp, result;

int matrix[1001][3] = { 0, };
int dpmatrix[1001][3] = { 0, };

void DP()
{
	for (int i = 1; i <= N; i++)
	{
		dpmatrix[i][0] = Min(dpmatrix[i-1][1], dpmatrix[i-1][2]) + matrix[i][0];
		dpmatrix[i][1] = Min(dpmatrix[i-1][0], dpmatrix[i-1][2]) + matrix[i][1];
		dpmatrix[i][2] = Min(dpmatrix[i-1][0], dpmatrix[i-1][1]) + matrix[i][2];
	}

	temp = Min(dpmatrix[N][0], dpmatrix[N][1]);
	result = Min(temp, dpmatrix[N][2]);
}

void Input()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> R >> G >> B;

		matrix[i][0] = R;
		matrix[i][1] = G;
		matrix[i][2] = B;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();

	DP();

	cout << result << "\n";

	return 0;
}