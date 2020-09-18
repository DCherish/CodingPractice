#include <iostream>
#include <queue>

using namespace std ;

int number ;
int N = 0 ;
int dx[4] = {-1, 0, 0, 1} ;
int dy[4] = {0, -1, 1, 0} ;

class pnt
{
public :
	int x ;
	int y ;
} ;

void BFS(char **matrix, bool **visited, int a, int b)
{
	queue <pnt> Q ;

	number = 0 ;

	pnt p ;

	p.x = a ;
	p.y = b ;

	visited[a][b] = true ;
	Q.push(p) ;
	number++ ;

	while( !Q.empty() )
	{
		int vx = Q.front().x ;
		int vy = Q.front().y ;

		Q.pop() ;

		for( int i = 0 ; i < 4 ; i++ )
		{
			int nx = vx + dx[i] ;
			int ny = vy + dy[i] ;

			if( nx < 0 || nx >= N || ny < 0 || ny >= N ) continue ;
			if( matrix[nx][ny] == '0' ) continue ;
			if( visited[nx][ny] == true ) continue ;

			visited[nx][ny] = true ;

			pnt np ;
			np.x = nx ;
			np.y = ny ;

			Q.push(np) ;
			number++ ;
		}	
	}
}

void heapify(int s[], int n, int i) // make maxheap
{
	int t = 0 ;
	int v = s[n] ;

	for( int j = 2 * n ; j <= i ; j = 2 * j ) // compare all of children
	{
		if( j < i && s[j] < s[j+1] ) // bigger child pick (that will be compared with its parent)
		{
			j = j + 1 ;
		}
		if( v >= s[j] ) // if parent > children, exit for loop
		{
			break ;
		}else // if parent < children, change between parent and children
		{
			s[j/2] = s[j] ;
		}
		t = 2 * j ;
	}
	s[t/2] = v ;
}

int main()
{
	cin >> N ;

	queue <int> C ;

	for(;;)
	{
		if( N >= 5 && N <= 25 )
		{
			char **matrix = new char *[N] ;
			bool **visited = new bool *[N] ;

			for( int i = 0 ; i < N ; i++ )
			{
				matrix[i] = new char[N] ;
				visited[i] = new bool[N] ;
			}

			for( int i = 0 ; i < N ; i++ )
			{
				for( int j = 0 ; j < N ; j++ )
				{
					cin >> matrix[i][j] ;
					visited[i][j] = false ;
				}
			}

			for( int i = 0 ; i < N ; i++ )
			{
				for( int j = 0 ; j < N ; j++ )
				{
					if( visited[i][j] == true || matrix[i][j] == '0' )
					{
						continue ;
					}else
					{
						BFS(matrix, visited, i, j) ;
						C.push(number) ;
					}
				}
			}
			
			break ;
		}else
		{
			continue ;
		}
	}

	int sz = C.size() ;

	cout << sz << endl ;

	int *s = new int[sz+1]  ;
	int *rs = new int[sz+1] ;
	
	for( int i = 1 ; i <= sz ; i++ )
	{
		s[i] = C.front() ;
		C.pop() ;
	}

	for( int i = sz / 2 ; i >= 1 ; i-- )
	{
		heapify(s, i, sz) ;
	}

	for( int i = sz - 1 ; i >= 0 ; i-- )
	{
		rs[i+1] = s[1] ; // Put max number of p array into last room of q array

		int temp = s[1] ;
		s[1] = s[i+1] ;
		s[i+1] = temp ; // last heap of p array goto first heap

		heapify(s, 1, i) ; // delete size 1
	}

	for( int i = 1 ; i <= sz ; i++ )
	{
		cout << rs[i] << endl ;
	}

	return 0 ;
}