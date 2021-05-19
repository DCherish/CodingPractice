#include <iostream>
#include <stack>

using namespace std ;

int N ;

char matrix[101][101] ;
bool visited[101][101] ;
char newmatrix[101][101] ;

void DFS(int u)
{
	for( int i = 1 ; i <= N ; i++ )
	{
		for( int j = 1 ; j <= N ; j++ )
		{
			visited[i][j] = false ;
		}
	}

	stack <int> S ;

	S.push(u) ;

	while( !S.empty() )
	{
		int visit = S.top() ;
		S.pop() ;

		for( int i = 1 ; i <= N ; i++ )
		{
			if( matrix[visit][i] == '1' && visited[visit][i] == false )
			{
				newmatrix[u][i] = '1' ;
				visited[visit][i] = true ;
				S.push(i) ;
			}
		}
	}
}

int main()
{
	cin >> N ;

	for( int i = 1 ; i <= N ; i++ )
	{
		for( int j = 1 ; j <= N ; j++ )
		{
			newmatrix[i][j] = '0' ;
		}
	}

	for( int i = 1 ; i <= N ; i++ )
	{
		for( int j = 1 ; j <= N ; j++ )
		{
			cin >> matrix[i][j] ;
		}
	}

	for( int i = 1 ; i <= N ; i++ )
	{
		DFS(i) ;
	}

	for( int i = 1 ; i <= N ; i++ )
	{
		for( int j = 1 ; j <= N ; j++ )
		{
			cout << newmatrix[i][j] << " " ;
		}
		cout << endl ;
	}

	return 0 ;
}