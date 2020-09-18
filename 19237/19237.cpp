#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int cnt = 0;
int matrix[20][20] = { 0, };
int cntmatrix[20][20] = { 0, };

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

class Shark
{
public:
	int x;
	int y;
	int dir;
	bool state;
	int p[5][5];
};

Shark shark[401];

void DFS()
{
	queue <int> Q;

	for( int i = 1 ; i <= M ; i++ )
	{
		Q.push(i);
	}

	while(!Q.empty())
	{
		int index = Q.front();
		Q.pop();

		int nx = shark[index].x;
		int ny = shark[index].y;
		int ndir = shark[index].dir;

		for( int i = 1 ; i < 4 ; i++ )
		{
			int vx = nx + dx[shark[index].p[ndir][i]];
			int vy = ny + dx[shark[index].p[ndir][i]];

			if( vx < 0 || vy < 0 || vx >= 4 || vy >= 4 ) continue;
			if( matrix[vx][vy] != 0 ) continue;

			
		}
	}
}

int main()
{
	int k;

	cin >> N >> M >> k;

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < N ; j++ )
		{
			cin >> matrix[i][j];

			if( matrix[i][j] != 0 )
			{
				shark[matrix[i][j]].x = i;
				shark[matrix[i][j]].y = j;

				cntmatrix[i][j] = k;			}
		}
	}

	for( int i = 1 ; i <= M ; i++ )
	{
		int d;
		cin >> d;
		shark[i].dir = d;
	}

	for( int a = 1 ; a <= M ; a++ )
	{
		for( int b = 1 ; b <= 4 ; b++ )
		{
			for( int c = 1 ; c <= 4 ; c++ )
			{
				int temp;
				cin >> temp;

				shark[a].p[b][c] = temp;
			}
		}
	}

	DFS();

	return 0;
}