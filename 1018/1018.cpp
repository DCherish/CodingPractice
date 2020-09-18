#include <iostream>

using namespace std ;

int C, R ; // C ; Column, R ; Row

int main()
{
	for(;;)
	{
		cin >> R >> C ;

		if( R < 8 || R > 50 || C < 8 || C > 50 )
		{
			//cout << "Setting Error :(\n Plz Re-insert Column and Row :)" << endl ;
		}else
		{
			break ;
		}
	}

	char** matrix = new char* [R] ; // 행렬 선언

	for( int i = 0 ; i < R ; i++ ) // 행렬 만들기
	{
		matrix[i] = new char[C] ;
	}

	char input = NULL ;

	for( int i = 0 ; i < R ; i++ ) // 원래의 체스판을 설정하기 (흑, 백 색칠하기)
	{
		for( int j = 0 ; j < C ; j++ )
		{
			cin >> input ;
			matrix[i][j] = input ;
		}
	}

	int tempcount = 0 ;
	int mincount = 99999 ;

	for( int i = 0 ; i <= R - 8 ; i++ )
	{
		for( int j = 0 ; j <= C - 8 ; j++ ) // 첫 번째 위치 기준으로 8 x 8을 비교
		{
			for( int a = 0 ; a < 8 ; a++ )
			{
				for( int b = 0 ; b < 8 ; b++ )
				{
					if( (a+b) % 2 != 0 ) // 첫 번째 칸과 홀수 칸 건너 뛴 것들이
					{
						if( matrix[i][j] == matrix[i+a][j+b] ) // 첫 번째 칸과 색이 같으면 안됨
						{
							tempcount++ ;
						}
					}else // 첫 번째 칸과 짝수 칸 건너 뛴 것들이
					{
						if( matrix[i][j] != matrix[i+a][j+b] ) // 첫 번째 칸과 색이 다르면 안됨
						{
							tempcount++ ;
						}
					}
				}
			}

			if ( tempcount > 32 ) // 첫 번째 칸을 기준으로 만약 비효율적으로 색을 더 많이 바꿨다면
			{
				tempcount = 64 - tempcount ; // 효율적으로 사실 첫 번째 칸을 바꿈으로써 효율적으로
			}

			if( tempcount < mincount )
			{
				mincount = tempcount ;
			}

			tempcount = 0 ;
		}
	}

	cout << mincount << endl ; // 가장 작게 바꾼 숫자는 ?

	return 0 ;
}