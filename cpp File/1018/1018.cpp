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

	char** matrix = new char* [R] ; // ��� ����

	for( int i = 0 ; i < R ; i++ ) // ��� �����
	{
		matrix[i] = new char[C] ;
	}

	char input = NULL ;

	for( int i = 0 ; i < R ; i++ ) // ������ ü������ �����ϱ� (��, �� ��ĥ�ϱ�)
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
		for( int j = 0 ; j <= C - 8 ; j++ ) // ù ��° ��ġ �������� 8 x 8�� ��
		{
			for( int a = 0 ; a < 8 ; a++ )
			{
				for( int b = 0 ; b < 8 ; b++ )
				{
					if( (a+b) % 2 != 0 ) // ù ��° ĭ�� Ȧ�� ĭ �ǳ� �� �͵���
					{
						if( matrix[i][j] == matrix[i+a][j+b] ) // ù ��° ĭ�� ���� ������ �ȵ�
						{
							tempcount++ ;
						}
					}else // ù ��° ĭ�� ¦�� ĭ �ǳ� �� �͵���
					{
						if( matrix[i][j] != matrix[i+a][j+b] ) // ù ��° ĭ�� ���� �ٸ��� �ȵ�
						{
							tempcount++ ;
						}
					}
				}
			}

			if ( tempcount > 32 ) // ù ��° ĭ�� �������� ���� ��ȿ�������� ���� �� ���� �ٲ�ٸ�
			{
				tempcount = 64 - tempcount ; // ȿ�������� ��� ù ��° ĭ�� �ٲ����ν� ȿ��������
			}

			if( tempcount < mincount )
			{
				mincount = tempcount ;
			}

			tempcount = 0 ;
		}
	}

	cout << mincount << endl ; // ���� �۰� �ٲ� ���ڴ� ?

	return 0 ;
}