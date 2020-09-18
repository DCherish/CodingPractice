#include <iostream>
#include <queue>

using namespace std ;

int t ;

int arr[14] = { 0, } ;
int narr[14] = { 0, } ;

queue <int> Q ;

void DFS(int from, int d)
{
	if(d == 6)
	{
		for( int i = 0 ; i < 6 ; i++ )
		{
			Q.push(narr[i]) ;
		}

		Q.push(-1) ;

		return ;
	}

	for( int i = from ; i < t ; i++ )
	{
		narr[d] = arr[i] ;
		DFS(i+1, d+1) ;
	}
}

int main()
{
	for(;;)
	{
		cin >> t ;

		if( t == 0 ) break ;

		if( t < 7 && t > 12 ) continue ;

		for( int i = 0 ; i < t ; i++ )
		{
			cin >> arr[i] ;
		}

		DFS(0, 0) ;

		Q.push(-2) ;
	}

	while( !Q.empty() )
	{
		if( Q.size() == 1 ) return 0 ;

		int index = Q.front() ;

		Q.pop() ;

		if( index == -1 )
		{
			cout << endl ;
		}else if( index == -2 )
		{
			cout << endl ;
		}else
		{
			cout << index << " " ;
		}
	}
}