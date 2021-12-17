#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct TRIE
{
	bool Finish;
	TRIE *Node[26];
	TRIE()
	{
		Finish = false;
		memset(Node, 0, sizeof(Node));
	}

    void Insert(char *Str)
    {
        if (*Str == NULL)
        {
            Finish = true;
            return;
        }

        int Cur = *Str - 'A';
        if (Node[Cur] == NULL) Node[Cur] = new TRIE();
        Node[Cur]->Insert(Str + 1);
    }

    void IsSorting(TRIE *N, char Str[], int Idx)
    {
        if (N->Finish == true) cout << Str << endl;
        for (int i = 0; i < 26; i++)
        {
            if (N->Node[i] != NULL)
            {
                char C = i + 'A';
                Str[Idx] = C;
                N->IsSorting(N->Node[i], Str, Idx + 1);
            }
        }
    }
};

int main(void)
{
    TRIE *Root = new TRIE();
    char *Str[5];
    Str[0] = (char *)"ZYX";
    Str[1] = (char *)"BCG";
    Str[2] = (char *)"ABC";
    Str[3] = (char *)"BDE";
    Str[4] = (char *)"ABCD";

    for (int i = 0; i < 5; i++)
    {
        Root->Insert(Str[i]);
    }

    for (int i = 0; i < 26; i++)
    {
        if (Root->Node[i] != NULL)
        {
            char T_Str[5] = { NULL };
            T_Str[0] = i + 'A';
            Root->IsSorting(Root->Node[i], T_Str, 1);
        }
    }

    return 0;
}