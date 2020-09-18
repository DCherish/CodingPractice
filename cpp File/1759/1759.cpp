#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int L;
int C;
char arr[16];
bool visited[16] = {false,};
deque<char> apb;

bool isOK()
{
	int aeiou = 0;
	int nthat = 0;

	for( int i = 0 ; i < L ; i++ )
	{
		if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
		{
			aeiou++;
		}else
		{
			nthat++;
		}
	}
	
	if( aeiou >= 1 && nthat >= 2 ) return true;
	else return false;
}

void code(int index, int depth)
{
	if(depth == L)
	{
		if(isOK() == true)
		{
			for(int i = 0 ; i < L ; i++)
			{
				cout << arr[i];
			}
			cout << endl;
			return;
		}else return;
	}

	for(int i = index ; i < C ; i++)
	{
		if(visited[i] == true) continue;
		visited[i] = true;
		arr[depth] = apb[i];
		code(i+1, depth+1);
		visited[i] = false;
	}
}

int main()
{
	cin >> L >> C ;

	if( L >= 3 && C >= 3 && L <= 15 && C <= 15 )
	{
		char t;
		
		for( int i = 0 ; i < C ; i++ )
		{
			cin >> t;
			apb.push_back(t);
		}

		sort(apb.begin(), apb.end());

		code(0, 0);
	}else
	{
		return 0;
	}

	return 0;
}