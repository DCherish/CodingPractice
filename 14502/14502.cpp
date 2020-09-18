#include <iostream>
#include <queue>

using namespace std ;

int N ;
int M ;

int dx[4] = {-1, 0, 0, 1} ;
int dy[4] = {0, -1, 1, 0} ;

int cnt ;
int maxcnt = 0 ;

int matrix[10][10] ;
int tmatrix[10][10] ;
bool visited[10][10] ;

class pnt
{
public:
	int x ;
	int y ;
} ;

void BFS()
{
	queue <pnt> Q ;
	
	cnt = 0 ;

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			if( matrix[i][j] == 2 )
			{
				visited[i][j] = true ;

				pnt p ;

				p.x = i ;
				p.y = j ;

				Q.push(p) ;
			}
		}
	}

	while( !Q.empty() )
	{
		int vx = Q.front().x ;
		int vy = Q.front().y ;

		Q.pop() ;

		for( int i = 0 ; i < 4 ; i++ )
		{
			int nx = vx + dx[i] ;
			int ny = vy + dy[i] ;

			if( nx < 0 || ny < 0 || nx >= N || ny >= M ) continue ;
			if( tmatrix[nx][ny] == 1 ) continue ;
			if( visited[nx][ny] == true ) continue ;

			tmatrix[nx][ny] = 2 ;
			visited[nx][ny] = true ;

			pnt np ;
			np.x = nx ;
			np.y = ny ;

			Q.push(np) ;

		}
	}

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			if( tmatrix[i][j] == 0 )
			{
				cnt++ ;
			}
		}
	}

	if( maxcnt < cnt )
	{
		maxcnt = cnt ;
	}
}

void Initialize(int v1, int v2, int v3, int v4, int v5, int v6)
{
	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			tmatrix[i][j] = matrix[i][j] ;
			visited[i][j] = false ;
		}

		tmatrix[v1][v2] = 1 ;
		tmatrix[v3][v4] = 1 ;
		tmatrix[v5][v6] = 0 ;
	}
}

int main()
{
	cin >> N >> M ;

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			cin >> matrix[i][j] ;
			tmatrix[i][j] = matrix[i][j] ;
		}
	}

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			if( tmatrix[i][j] == 0 )
			{
				tmatrix[i][j] = 1 ;

				for( int a = i ; a < N ; a++ )
				{
					for( int b = 0 ; b < M ; b++ )
					{
						if( tmatrix[a][b] == 0 )
						{
							tmatrix[a][b] = 1 ;
							
							for( int p = a ; p < N ; p++ )
							{
								for( int q = 0 ; q < M ; q++ )
								{
									if( tmatrix[p][q] == 0 )
									{
										tmatrix[p][q] = 1 ;

										BFS() ;
										Initialize(i, j, a, b, p, q) ;
									}
								}
							}

							tmatrix[a][b] = 0 ;
						}
					}
				}

				tmatrix[i][j] = 0 ;
			}
		}
	}

	cout << maxcnt << endl ;

	return 0 ;
}