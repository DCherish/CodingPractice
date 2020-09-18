#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class mapinfo
{
public:
	int x;
	int y;
	int dir;
	bool state;
};

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int matrix[4][4] = { 0, };
int maxv = 0;
mapinfo mi[17];

void CopyMatrix(int A[][4], int B[][4], mapinfo ma[], mapinfo mb[])
{
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			A[i][j] = B[i][j];
		}
	}

	for( int i = 1 ; i <= 16 ; i++ )
	{
		ma[i] = mb[i];
	}
}

void MoveFish()
{
	queue <int> Q;

	for( int i = 1 ; i <= 16 ; i++ )
	{
		Q.push(i);
	}

	while(!Q.empty())
	{
		int index = Q.front();
		Q.pop() ;

		int nx = mi[index].x;
		int ny = mi[index].y;
		int ndir = mi[index].dir;
		bool nstate = mi[index].state;

		for( int i = 0 ; i < 8 ; i++ )
		{
			int imdir = (ndir + i) % 8;

			if( nstate == false ) break;
			if( nx + dx[imdir] < 0 || ny + dy[imdir] < 0 || nx + dx[imdir] >= 4 || ny + dy[imdir] >= 4 ) continue;
			if( matrix[nx+dx[imdir]][ny+dy[imdir]] == -1 ) continue;

			swap(matrix[nx][ny], matrix[nx+dx[imdir]][ny+dy[imdir]]);
			
			mi[matrix[nx][ny]].x = nx;
			mi[matrix[nx][ny]].y = ny;

			mi[matrix[nx+dx[imdir]][ny+dy[imdir]]].x = nx+dx[imdir];
			mi[matrix[nx+dx[imdir]][ny+dy[imdir]]].y = ny+dy[imdir];
			mi[matrix[nx+dx[imdir]][ny+dy[imdir]]].dir = imdir;

			break;
		}
	}
}

void DFS(int x, int y, int dir, int sum)
{
	if( maxv < sum )
	{
		maxv = sum;
	}

	int tempmatrix[4][4];
	mapinfo tempmi[17];

	CopyMatrix(tempmatrix, matrix, tempmi, mi);
	MoveFish();

	for( int i = 1 ; i <= 3 ; i++ )
	{
		int tx = x + dx[dir] * i;
		int ty = y + dy[dir] * i;

		if( tx < 0 || ty < 0 || tx >= 4 || ty >= 4 ) continue;
		if( matrix[tx][ty] == 0 ) continue;

		int tempvalue = matrix[tx][ty];

		mi[tempvalue].state = false;
		matrix[tx][ty] = -1;
		matrix[x][y] = 0;

		DFS(tx, ty, mi[tempvalue].dir, sum + tempvalue);

		matrix[x][y] = -1;
		matrix[tx][ty] = tempvalue;
		mi[tempvalue].state = true;
	}

	CopyMatrix(matrix, tempmatrix, mi, tempmi);
}

void GoShark()
{
	int init = matrix[0][0];
	int tempdir = mi[init].dir;
	mi[init].state = false;
	matrix[0][0] = -1;

	DFS(0, 0, tempdir, init);

	cout << maxv << endl;
}

int main()
{
	for( int i = 0 ; i < 4 ; i++ )
	{
		for( int j = 0 ; j < 4 ; j++ )
		{
			int a;
			int b;
			cin >> a >> b;

			matrix[i][j] = a;
			mi[a].x = i;
			mi[a].y = j;
			mi[a].dir = b-1;
			mi[a].state = true;
		}
	}

	GoShark();

	return 0;
}