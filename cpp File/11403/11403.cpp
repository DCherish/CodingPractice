#include <iostream>
#include <queue>

using namespace std ;

int N ;

char matrix[101][101] ;
bool visited[101][101] ;
char newmatrix[101][101] ;

void BFS(int u)
{
	for( int i = 1 ; i <= N ; i++ )
	{
		for( int j = 1 ; j <= N ; j++ )
		{
			visited[i][j] = false ;
		}
	}

	queue <int> Q ;

	Q.push(u) ;

	while( !Q.empty() )
	{
		int visit = Q.front() ;
		Q.pop() ;

		for( int i = 1 ; i <= N ; i++ )
		{
			if( matrix[visit][i] == '1' && visited[visit][i] == false )
			{
				newmatrix[u][i] = '1' ;
				visited[visit][i] = true ;
				Q.push(i) ;
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
		BFS(i) ;
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