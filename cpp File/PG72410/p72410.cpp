#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    string temp = "";

    for (int i = 0; i < new_id.length(); i++) // 1, 2단계
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] += 32;
            temp = temp + new_id[i]; 
        }
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            temp += new_id[i];
        }
        else if (new_id[i] >= 'a' && new_id[i] <= 'z')
        {
            temp += new_id[i];
        }
        else if (new_id[i] >= '0' && new_id[i] <= '9')
        {
            temp += new_id[i];
        }
        else continue;
    }

    new_id = "";

    for (int i = 0; i < temp.length(); i++) // 3단계
    {
        if (temp[i] == '.' && temp[i + 1] == '.') continue;
        else new_id += temp[i];
    }

    if (new_id[0] == '.') // 4단계
    {
        new_id = new_id.substr(1, new_id.length() - 1);
    }

    if (new_id[new_id.length() - 1] == '.') // 4단계
    {
        new_id = new_id.substr(0, new_id.length() - 1);
    }

    if (new_id == "") // 5단계
    {
        new_id = "a";
    }

    if (new_id.length() >= 16) // 6단계
    {
        new_id = new_id.substr(0, 15);

        if (new_id[new_id.length() - 1] == '.')
        {
            new_id = new_id.substr(0, new_id.length() - 1);
        }
    }

    if (new_id.length() <= 2) // 7단계
    {
        string tempstr = new_id.substr(new_id.length() - 1, 1);

        while (new_id.length() < 3)
        {
            new_id += tempstr;
        }
    }

    answer = new_id;

    return answer;
}