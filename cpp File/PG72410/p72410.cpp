#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    string temp = "";

    for (int i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = tolower(new_id[i]);
            temp += new_id[i];
        }
        else if (new_id[i] >= '0' && new_id[i] <= '9')
        {
            temp += new_id[i];
        }
        else if (new_id[i] >= 'a' && new_id[i] <= 'z')
        {
            temp += new_id[i];
        }
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            temp += new_id[i];
        }
    }

    new_id = "";

    for (int i = 0; i < temp.length() - 1; i++)
    {
        if (temp[i] == '.' && temp[i + 1] == '.')
            continue;
        else
            new_id += temp[i];
    }

    new_id += temp[temp.length() - 1];

    if (new_id[0] == '.')
    {
        new_id = new_id.substr(1, new_id.length() - 1);
    }

    if (new_id[new_id.length() - 1] == '.')
    {
        new_id = new_id.substr(0, new_id.length() - 1);
    }

    if (new_id == "")
    {
        new_id = "a";
    }

    if (new_id.length() >= 16)
    {
        new_id = new_id.substr(0, 15);

        if (new_id[new_id.length() - 1] == '.')
        {
            new_id = new_id.substr(0, new_id.length() - 1);
        }
    }

    if (new_id.length() <= 2)
    {
        while (new_id.length() < 3)
        {
            new_id += new_id[new_id.length() - 1];
        }
    }

    answer = new_id;

    return answer;
}