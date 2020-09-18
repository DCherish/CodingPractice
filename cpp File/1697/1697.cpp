#include <iostream>
#include <queue>

using namespace std ;

int N = 0 ;
int K = 0 ;

bool state = false ;

bool visited[100000] = { false, } ; // All initialize

class value
{
public :
	int num ;
	int cnt ;
};

int main()
{
	for(;;)
	{
		cin >> N >> K ;

		if( N < 0 || K < 0 || N > 100000 || K > 100000 ) continue ;

		queue <value> Q ;

		value v ;

		visited[N] = true ;
		v.num = N ;
		v.cnt = 0 ;

		Q.push(v) ;

		while( !Q.empty() )
		{
			int vs = Q.front().num ;
			int nc = Q.front().cnt ;

			Q.pop() ;

			if( vs == K )
			{
				cout << nc << endl ;
				state = true ;
				break ;
			}

			if( vs-1 >= 0 && visited[vs-1] == false )
			{
				visited[vs-1] = true ;

				value pv ;

				pv.num = vs - 1 ;
				pv.cnt = nc + 1 ;
				Q.push(pv) ;
			}

			if( vs+1 <= 100000 && visited[vs+1] == false )
			{
				visited[vs+1] = true ;
				
				value pv ;

				pv.num = vs + 1 ;
				pv.cnt = nc + 1 ;
				Q.push(pv) ;
			}

			if( 2*vs <= 100000 && visited[2*vs] == false )
			{
				visited[2*vs] = true ;
				
				value pv ;

				pv.num = 2 * vs ;
				pv.cnt = nc + 1 ;
				Q.push(pv) ;
			}
		}

		if( state == true )
		{
			break ;
		}
	}

	return 0 ;
}