#include <iostream>

using namespace std;

int Cnt; // C ; Count
int BJN; // BJN ; BlackJackNumber

int main()
{
	for (;; )
	{
		//cout << "Count : ";
		cin >> Cnt; // ī�� �� �Է�

		if (Cnt >= 3 && Cnt <= 100)
		{
			//cout << "BlackJackNumber : ";
			cin >> BJN; // ���� Number ����

			if (BJN >= 10 && BJN <= 300000)
			{
				break;
			}
			else // ���� Number ���� ���� ó��
			{
				//cout << "BlackJackNumber Error :(\n Plz Re-insert BlackJackNumber :)" << endl;
			}
		}
		else // ī�� �� ���� ���� ó��
		{
			//cout << "Count Error :(\n Plz Re-insert Count :)" << endl;
		}
	}

	int input = 0;

	int* CA = new int[Cnt]; // make a Card-Array

	for (int i = 0; i < Cnt; i++)
	{
		cin >> input; // ī���� ���� �Է�

		if (input < 0) // ī���� ���ڴ� �ݵ�� ���� ����, ������ ���� ó��
		{
			//cout << "Input Error :(\n Plz Re-insert Input :)" << endl;
			i--;
		}
		else
		{
			CA[i] = input;
		}
	}

	int tempmax = 0; // ��� ī�� ���ڵ��� ���� �����
	int max = -99999; // �ִ��� ���迡 ����� ���ڸ� ����

	for (int a = 0; a <= Cnt - 3; a++)
	{
		for (int b = a + 1; b <= Cnt - 2; b++)
		{
			for (int c = b + 1; c <= Cnt - 1; c++)
			{
				tempmax = CA[a] + CA[b] + CA[c] ;

				if (tempmax > max && tempmax <= BJN) // ���迡 ���� ����� �� Update
				{
					max = tempmax ;
				}
			}
		}
	}

	cout << max << endl ; // ����� ���� ����� ���� ?

	return 0 ;
}