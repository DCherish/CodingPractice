#include <iostream>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int R;
int C;

int maxcnt = 0;

char arr[20][20];
bool visited[26] = {false,};

void DFS(int depth, int i, int j)
{
    if( maxcnt < depth )
    {
        maxcnt = depth;
    }

    for( int k = 0 ; k < 4 ; k++ )
    {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if( nx < 0 || ny < 0 || nx >= R || ny >= C ) continue;

        int tempv = (int) arr[nx][ny];
        if( visited[tempv-65] == true) continue;

        visited[tempv-65] = true;
        DFS(depth+1, nx, ny);
        visited[tempv-65] = false;
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

        int initv = (int) arr[0][0];
        visited[initv-65] = true;
        DFS(1, 0, 0);

        cout << maxcnt << endl;
    }else
    {
        return 0;
    }

    return 0;
}