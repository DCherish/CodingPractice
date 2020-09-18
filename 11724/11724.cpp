#include <iostream>
#include <queue>

using namespace std ;

int N ;
int M ;

int cnt = 0 ;

int matrix[1000][1000] = { 0, } ;
bool visited[1000] = { false, } ;

void BFS()
{
	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < N ; j++ )
		{
			if( matrix[i][j] == 1 && visited[j] == false )
			{
				visited[j] = true ;

				queue <int> Q ;

				Q.push(j) ;

				while( !Q.empty() )
				{
					int visit = Q.front() ;
					Q.pop() ;

					for( int k = 0 ; k < N ; k++ )
					{
						if( matrix[visit][k] == 1 && visited[k] == false ) 
						{
							visited[k] = true ;

							Q.push(k) ;
						}
					}
				}

				cnt++ ;
			}
		}
	}

}

void Isthereanymore()
{
	for( int i = 0 ; i < N ; i++ )
	{
		int tcnt = 0 ;
		bool state = false ;

		for( int j = 0 ; j < N ; j++ )
		{
			if( matrix[i][j] == 1 ) 
			{
				break ;
			}

			tcnt++ ;

			if( tcnt == N ) cnt++ ;
		}
	}
}

int main()
{
	int u = 0 ;
	int v = 0 ;

	cin >> N >> M ;

	if( N < 1 || N > 1000 || M < 0 || M > N*(N-1)/2 ) return 0 ;

	for( int i = 0 ; i < M ; i++ )
	{
		cin >> u >> v ;

		if( u < 1 || v < 1 || u > N || v > N || u == v )
		{
			i-- ;
			continue ;
		}

		matrix[u-1][v-1] = 1 ;
		matrix[v-1][u-1] = 1 ;
	}

	BFS() ;

	Isthereanymore() ;

	cout << cnt << endl ;

	return 0 ;
}