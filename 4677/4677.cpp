#include <iostream>
#include <queue>

int C = 0 ;
int R = 0 ;
int cnt = 0 ;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1} ;
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1} ;

using namespace std ;

class pnt
{
public :
	int x, y ;
} ;

void BFS(char **matrix, bool **visited, int a, int b)
{
	queue <pnt> Q ;

	pnt p ;

	p.x = a ;
	p.y = b ;

	visited[a][b] = true ;
	Q.push(p) ;

	while( !Q.empty() )
	{
		int vx = Q.front().x ;
		int vy = Q.front().y ;

		Q.pop() ;

		for( int i = 0 ; i < 8 ; i++ )
		{
			int nx = vx + dx[i] ;
			int ny = vy + dy[i] ;

			if( nx < 0 || nx >= C || ny < 0 || ny >= R ) continue ;
			if( matrix[nx][ny] == '*' ) continue ;
			if( visited[nx][ny] == true ) continue ;

			visited[nx][ny] = true ;

			pnt np ;
			np.x = nx ;
			np.y = ny ;

			Q.push(np) ;
		}
	}
	cnt++ ;
}

int main()
{
	queue <int> CNT ;

	for(;;)
	{
		cin >> C >> R ; // size of Column & Row

		cnt = 0 ;

		if( C == 0 )
		{
			break ;
		}

		char **matrix = new char *[C] ; // make a matrix outline
		bool **visited = new bool *[C] ;

		for( int i = 0 ; i < C ; i++ )
		{
			matrix[i] = new char[R] ;
			visited[i] = new bool[R] ;
		}
		
		for( int i = 0 ; i < C ; i++ )
		{
			for( int j = 0 ; j < R ; j++ )
			{
				cin >> matrix[i][j] ;
				visited[i][j] = false ;
			}
		}

		for( int i = 0 ; i < C ; i++ ) // ÃÊ±âÈ­
		{
			for( int j = 0 ; j < R ; j++ )
			{
				if( visited[i][j] == true || matrix[i][j] == '*' )
				{
					continue ;
				}else
				{
					BFS(matrix, visited, i, j) ;
				}
			}
		}

		CNT.push(cnt) ;
	}

	while( !CNT.empty() )
	{
		cout << CNT.front() << endl ;
		CNT.pop() ;
	}

	return 0 ;
}