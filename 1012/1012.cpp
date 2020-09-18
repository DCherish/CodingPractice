#include <iostream>
#include <queue>

using namespace std ;

int dx[4] = {0, -1, 1, 0} ;
int dy[4] = {-1, 0, 0, 1} ;

int M = 0 ;
int N = 0 ;
int K = 0 ;

int cnt ;

class pnt
{
public :
	int x ;
	int y ;
} ;

void BFS(int **matrix, bool **visited)
{
	queue <pnt> Q ;

	bool state = false ;

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < M ; j++ )
		{
			if( matrix[j][i] == 1 && visited[j][i] == false )
			{
				visited[j][i] = true ;

				pnt p ;
				p.x = j ;
				p.y = i ;

				Q.push(p) ;

				while( !Q.empty() )
				{
					int vx = Q.front().x ;
					int vy = Q.front().y ;

					Q.pop() ;

					for( int a = 0 ; a < 4 ; a++ )
					{
						int nx = vx + dx[a] ;
						int ny = vy + dy[a] ;

						if( nx < 0 || ny < 0 || nx >= M || ny >= N ) continue ;
						if( visited[nx][ny] == true ) continue ;
						if( matrix[nx][ny] == 0 ) continue ;

						visited[nx][ny] = true ;

						pnt np ;
						np.x = nx ;
						np.y = ny ;

						Q.push(np) ;
					}
				}
				cnt++ ;
			}
		}
	}
}

int main()
{
	int T = 0 ;
	int Tcnt = 0 ;

	queue <int> S ;

	cin >> T ;

	for(;;)
	{
		if( Tcnt == T ) break ;

		cin >> M >> N >> K ;

		if( M < 1 || N < 1 || M > 50 || N > 50 || K < 1 || K > 2500 ) continue ;

		int **matrix = new int *[M] ;
		bool **visited = new bool *[M] ;	

		for( int i = 0 ; i < M ; i++ )
		{
			matrix[i] = new int [N] ;
			visited[i] = new bool [N] ;
		}

		cnt = 0 ;

		for( int i = 0 ; i < N ; i++ )
		{
			for( int j = 0 ; j < M ; j++ )
			{
				matrix[j][i] = 0 ;
				visited[j][i] = false ;
			}
		}

		int px = 0 ;
		int py = 0 ;

		for( int i = 0 ; i < K ; i++ )
		{
			cin >> px >> py ;
			matrix[px][py] = 1 ;
		}

		BFS(matrix, visited) ;
		
		S.push(cnt) ;

		Tcnt++ ;
	}

	int sz = S.size() ;

	for( int i = 0 ; i < sz ; i++ )
	{
		cout << S.front() << endl ;
		S.pop() ;
	}

	return 0 ;
}