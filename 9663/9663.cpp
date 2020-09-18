#include <iostream>

using namespace std ;

bool matrix[15][15] = { false, } ;

int N ;
int answer = 0 ;

bool IsVaild(int a, int b)
{
	int i, j ;

	for( i = 0 ; i < b ; i++ )
	{
		if( matrix[a][i] == true ) return false ;
	}

	for( i = 0 ; i < a ; i++ )
	{
		if( matrix[i][b] == true ) return false ;
	}

	for( i = a-1, j = b-1 ; i >= 0 && j >= 0 ; i--, j-- )
	{
		if( matrix[i][j] == true ) return false ;
	}

	for( i = a+1, j = b-1 ; i < N && j >= 0 ; i++, j-- )
	{
		if( matrix[i][j] == true ) return false ;
	}

	return true ;
}

void NQueen(int cnt)
{
	if( cnt == N )
	{
		answer++ ;
		return ;
	}

	for( int i = 0 ; i < N ; i++ )
	{
		if( matrix[i][cnt] != true && IsVaild(i, cnt) == true )
		{
			matrix[i][cnt] = true ;
			NQueen(cnt+1) ;
			matrix[i][cnt] = false ;
		}
	}
}

int main()
{
	cin >> N ;

	NQueen(0) ;

	cout << answer << endl ;

	return 0 ;
}