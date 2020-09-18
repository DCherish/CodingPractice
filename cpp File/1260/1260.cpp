#include <iostream>
#include <queue>
#include <stack>
#include <vector>

int N = 0 ;
int M = 0;

int V = 0 ;

using namespace std ;

void ShowDFS(vector <vector <int>> graph, vector <bool> visited)
{
	for( int i = 0 ; i < visited.size() ; i++ )
	{
		visited[i] = false ;
	}

	stack <int> S ;
	S.push(V-1) ;

	while( !S.empty() )
	{
		int visit = S.top() ;
		S.pop() ;

		int cnt = 0 ;
		int ncnt = 0 ;

		if( visited[visit] == false )
		{
			visited[visit] = true ;

			cout << visit+1 << " " ; 

			for( int i = 0 ; i < graph[visit].size() ; i++ )
			{
				if( visited[graph[visit][i]] == false )
				{
					cnt++ ;
				}
			}

			int *ready = new int[cnt] ;

			for( int i = 0 ; i < graph[visit].size() ; i++ )
			{
				if( visited[graph[visit][i]] == false )
				{
					ready[ncnt] = graph[visit][i] ;
					ncnt++ ;
				}
			}

			for( int i = ncnt-1 ; i >= 1 ; i-- )
			{
				for( int j = 0 ; j < i ; j++ )
				{
					if( ready[j] < ready[j+1] )
					{
						int temp = 0 ;

						temp = ready[j] ;
						ready[j] = ready[j+1] ;
						ready[j+1] = temp ;
					}
				}
			}

			for( int i = 0 ; i < ncnt ; i++ )
			{
				S.push(ready[i]) ;
			}
		}
	}
	cout << endl ;
}

void ShowBFS(vector <vector <int>> graph, vector <bool> visited)
{
	for( int i = 0 ; i < visited.size() ; i++ )
	{
		visited[i] = false ;
	}

	queue <int> Q ;
	Q.push(V-1) ;

	while( !Q.empty() )
	{
		int visit = Q.front() ;
		Q.pop() ;

		int cnt = 0 ;
		int ncnt = 0 ;

		if( visited[visit] == false )
		{
			visited[visit] = true ;

			cout << visit+1 << " " ; 

			for( int i = 0 ; i < graph[visit].size() ; i++ )
			{
				if( visited[graph[visit][i]] == false )
				{
					cnt++ ;
				}
			}

			int *ready = new int[cnt] ;

			for( int i = 0 ; i < graph[visit].size() ; i++ )
			{
				if( visited[graph[visit][i]] == false )
				{
					ready[ncnt] = graph[visit][i] ;
					ncnt++ ;
				}
			}

			for( int i = ncnt-1 ; i >= 1 ; i-- )
			{
				for( int j = 0 ; j < i ; j++ )
				{
					if( ready[j] > ready[j+1] )
					{
						int temp = 0 ;

						temp = ready[j] ;
						ready[j] = ready[j+1] ;
						ready[j+1] = temp ;
					}
				}
			}

			for( int i = 0 ; i < ncnt ; i++ )
			{
				Q.push(ready[i]) ;
			}
		}
	}
	cout << endl ;
}

int main()
{
	for(;;)
	{
		cin >> N >> M >> V ;

		if( N < 0 || N > 1000 || M < 0 || M > 10000 || V < 0 || V > N )
		{
			continue ;
		}

		vector <vector <int>> graph(N) ;
		vector <bool> visited(N) ;

		for( int i = 0 ; i < M ; i++ )
		{
			int p ;
			int q ; 
			cin >> p >> q ;

			graph[p-1].push_back(q-1) ;
			graph[q-1].push_back(p-1) ;
		}

		ShowDFS(graph, visited) ;
		ShowBFS(graph, visited) ;
		break ;
	}
	
	return 0 ;
}