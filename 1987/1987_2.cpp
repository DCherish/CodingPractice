#include <iostream>
#include <stack>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int R;
int C;

int initv;
int tempv;

int maxcnt = 0;
char arr[20][20];

class pnt
{
public :
	int x;
	int y;
	int cnt;
	bool visit[26] = {false,};
};

void DFS()
{
	stack <pnt> Q;
	pnt p;

	p.x = 0;
	p.y = 0;
	p.cnt = 1;

	Q.push(p);

	while( !Q.empty() )
	{
		pnt np;
		np.x = Q.top().x;
		np.y = Q.top().y;
		np.cnt = Q.top().cnt;

		for(int i = 0 ; i < 26 ; i++)
		{
			np.visit[i] = Q.top().visit[i];
		}

		initv = (int) arr[np.x][np.y];
		np.visit[initv-65] = true;

		Q.pop();

		if( maxcnt < np.cnt )
		{
			maxcnt = np.cnt;
		}

		for( int i = 0 ; i < 4 ; i++ )
		{
			int nx = dx[i] + np.x;
			int ny = dy[i] + np.y;

			if( nx < 0 || ny < 0 || nx >= R || ny >= C ) continue;

			tempv = (int) arr[nx][ny];
			if( np.visit[tempv-65] == true ) continue;

			pnt cp;

			cp.x = nx;
			cp.y = ny;
			cp.cnt = np.cnt + 1;

			for(int i = 0 ; i < 26 ; i++)
			{
				cp.visit[i] = np.visit[i];
			}

			Q.push(cp);
		}
	}
}

int main()
{
	cin >> R >> C;

	if( R >= 1 && C >= 1 && R <= 20 && C <= 20 )
	{
		for( int i = 0 ; i < R ; i++ )
		{
			for( int j = 0 ; j < C ; j++ )
			{
				cin >> arr[i][j];
			}
		}

		DFS();

		cout << maxcnt << endl;
	}else
	{
		return 0;
	}

	return 0;
}