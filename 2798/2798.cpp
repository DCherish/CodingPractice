#include <iostream>

using namespace std;

int Cnt; // C ; Count
int BJN; // BJN ; BlackJackNumber

int main()
{
	for (;; )
	{
		//cout << "Count : ";
		cin >> Cnt; // 카드 수 입력

		if (Cnt >= 3 && Cnt <= 100)
		{
			//cout << "BlackJackNumber : ";
			cin >> BJN; // 블랙잭 Number 설정

			if (BJN >= 10 && BJN <= 300000)
			{
				break;
			}
			else // 블랙잭 Number 범위 예외 처리
			{
				//cout << "BlackJackNumber Error :(\n Plz Re-insert BlackJackNumber :)" << endl;
			}
		}
		else // 카드 수 범위 예외 처리
		{
			//cout << "Count Error :(\n Plz Re-insert Count :)" << endl;
		}
	}

	int input = 0;

	int* CA = new int[Cnt]; // make a Card-Array

	for (int i = 0; i < Cnt; i++)
	{
		cin >> input; // 카드의 숫자 입력

		if (input < 0) // 카드의 숫자는 반드시 양의 정수, 음수는 예외 처리
		{
			//cout << "Input Error :(\n Plz Re-insert Input :)" << endl;
			i--;
		}
		else
		{
			CA[i] = input;
		}
	}

	int tempmax = 0; // 모든 카드 숫자들의 합을 고려함
	int max = -99999; // 최대한 블랙잭에 가까운 숫자를 저장

	for (int a = 0; a <= Cnt - 3; a++)
	{
		for (int b = a + 1; b <= Cnt - 2; b++)
		{
			for (int c = b + 1; c <= Cnt - 1; c++)
			{
				tempmax = CA[a] + CA[b] + CA[c] ;

				if (tempmax > max && tempmax <= BJN) // 블랙잭에 가장 가까운 수 Update
				{
					max = tempmax ;
				}
			}
		}
	}

	cout << max << endl ; // 블랙잭과 가장 가까운 수는 ?

	return 0 ;
}