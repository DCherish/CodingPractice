#include <iostream>
#include <queue>

using namespace std ;

int N = 0 ;
int M = 0 ;

int dx[4] = {-1, 0, 0, 1} ;
int dy[4] = {0, -1, 1, 0} ;

class pnt
{
public:
	int x;
	int y;
	int cnt;
};

void SearchEND(char **matrix, bool **visited)
{
	queue <pnt> Q ;
	pnt p ;
	int min = 9999 ;

	p.x = 0 ;
	p.y = 0 ;
	p.cnt = 0 ;

	visited[p.x][p.y] = true ;
	p.cnt = 1 ;
	
	Q.push(p) ;

	while( !Q.empty() )
	{
		int vx = Q.front().x ;
		int vy = Q.front().y ;
		int nc = Q.front().cnt ;

		Q.pop() ;

		for( int i = 0 ; i < 4 ; i++ )
		{
			int nx = vx + dx[i] ;
			int ny = vy + dy[i] ;

			if( nx < 0 || ny < 0 || nx >= N || ny >= M ) continue ;

			if( nx == N - 1 && ny == M - 1 )
			{
				if( min > nc + 1 )
				{
					min = nc + 1  ;
				}
				continue ;
			}

			if( matrix[nx][ny] == '0' )	continue ;
			if( visited[nx][ny] == true ) continue ;
			
			visited[nx][ny] = true ;

			pnt np ;
			np.x = nx ;
			np.y = ny ;
			np.cnt = nc + 1 ;

			Q.push(np) ;
		}
	}

	cout << min << endl ;
}

int main()
{
	for(;;)
	{
		cin >> N >> M ;

		if( N < 2 || N > 100 || M < 2 || M > 100 )
		{
			continue ;
		}else
		{
			char **matrix = new char *[N] ;
			bool **visited = new bool *[N] ;

			for( int i = 0 ; i < N ; i++ )
			{
				matrix[i] = new char[M] ;
				visited[i] = new bool[M] ;
			}

			for( int i = 0 ; i < N ; i++ )
			{
				for( int j = 0 ; j < M ; j++ )
				{
					cin >> matrix[i][j] ;
					visited[i][j] = false ;
				}
			}

			SearchEND(matrix, visited) ;

			break ;
		}
	}

	return 0 ;
}