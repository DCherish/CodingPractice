#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int mx = 0;

int n, m;
char Cmatrix[1001][1001];
int Imatrix[1001][1001];

void Calculate(int i, int j)
{
	Imatrix[i][j] = min({Imatrix[i-1][j], Imatrix[i-1][j-1], Imatrix[i][j-1]}) + 1;
}

void isMax(int i, int j)
{
	if( Imatrix[i][j] > mx ) 
	{
		mx = Imatrix[i][j];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for( int i = 0 ; i < n ; i++ )
	{
		string s;
		cin >> s;

		for( int j = 0 ; j < m ; j++ )
		{
			Cmatrix[i+1][j+1] = s.at(j);
			Imatrix[i+1][j+1] = ((int) Cmatrix[i+1][j+1]) - 48;
		}
	}

	for( int i = 1 ; i <= n ; i++ )
	{
		for( int j = 1 ; j <= m ; j++ )
		{
			if( Imatrix[i][j] == 1 )
			{
				Calculate(i, j);
				isMax(i, j);
			}
		}
	}

	cout << mx * mx << "\n";
}