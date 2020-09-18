#include <iostream>
#include <queue>

int N = 0 ;
int M = 0 ;

int dx[4] = {-1, 0, 0, 1} ;
int dy[4] = {0, -1, 1, 0} ;

int lastcnt = 0 ;

using namespace std ;

class pnt
{
public :
	int x ;
	int y ;
	int cnt ;
} ;

void BFS(int **matrix, bool **visited)
{
	queue <pnt> Q ;
	pnt p ;

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			if( matrix[i][j] == 1 )
			{
				p.x = i ;
				p.y = j ;
				p.cnt = 0 ;

				visited[p.x][p.y] = true ;

				Q.push(p) ;
			}
		}
	}

	while( !Q.empty() )
	{
		int vx = Q.front().x ;
		int vy = Q.front().y ;
		int nc = Q.front().cnt ;

		Q.pop() ;

		lastcnt = nc ;

		for( int i = 0 ; i < 4 ; i++ )
		{
			int nx = vx + dx[i] ;
			int ny = vy + dy[i] ;

			if( nx < 0 || ny < 0 || nx >= N || ny >= M ) continue ;
			if( matrix[nx][ny] == -1 ) continue ;
			if( visited[nx][ny] == true ) continue ;

			visited[nx][ny] = true ;

			pnt np ;

			np.x = nx ;
			np.y = ny ;
			np.cnt = nc + 1 ;

			Q.push(np) ;
		}
	}

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			if( matrix[i][j] == 0 && visited[i][j] == false )
			{
				lastcnt = -1 ;
			}
		}
	}
}

int main()
{
	for(;;)
	{
		cin >> M >> N ;

		if( M < 2 || N < 2 || M > 1000 || N > 1000 ) continue ;
		
		int **matrix = new int *[N] ;
		bool **visited = new bool *[N] ;

		for( int i = 0 ; i < N ; i++ )
		{
			matrix[i] = new int [M] ;
			visited[i] = new bool [M] ;
		}

		for( int i = 0 ; i < N ; i++ )
		{
			for( int j = 0 ; j < M ; j++ )
			{
				cin >> matrix[i][j] ;
				visited[i][j] = false ;
			}
		}

		BFS(matrix, visited) ;
		cout << lastcnt << endl ;

		break ;
	}

	return 0 ;
}