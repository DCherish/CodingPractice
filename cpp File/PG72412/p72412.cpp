#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> db[3][2][2][2];

    for (int i = 0; i < info.size(); i++)
    {
        vector<int> vec;

        stringstream ss(info[i]);
        string token;

        while (getline(ss, token, ' '))
        {
            if (token == "java" || token == "backend"
                || token == "junior" || token == "pizza")
            {
                vec.push_back(0);
            }
            else if (token == "python" || token == "frontend"
                || token == "senior" || token == "chicken")
            {
                vec.push_back(1);
            }
            else if (token == "cpp")
            {
                vec.push_back(2);
            }
            else
            {
                vec.push_back(stoi(token));
            }
        }

        db[vec[0]][vec[1]][vec[2]][vec[3]].push_back(vec[4]);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    sort(db[i][j][k][l].begin(), db[i][j][k][l].end());
                }
            }
        }
    }

    for (int i = 0; i < query.size(); i++)
    {
        vector<int> vec;

        int ai, bi, aj, bj, ak, bk, al, bl, score;

        stringstream ss(query[i]);
        string token;

        while (getline(ss, token, ' '))
        {
            if (token == "java" || token == "backend"
                || token == "junior" || token == "pizza")
            {
                vec.push_back(0);
            }
            else if (token == "python" || token == "frontend"
                || token == "senior" || token == "chicken")
            {
                vec.push_back(1);
            }
            else if (token == "cpp")
            {
                vec.push_back(2);
            }
            else if (token == "-")
            {
                vec.push_back(3);
            }
            else if (token == "and")
            {
                continue;
            }
            else
            {
                vec.push_back(stoi(token));
            }
        }

        if (vec[0] == 0) // java
        {
            ai = 0;
            bi = 0;
        }
        else if (vec[0] == 1) // python
        {
            ai = 1;
            bi = 1;
        }
        else if (vec[0] == 2) // cpp
        {
            ai = 2;
            bi = 2;
        }
        else if (vec[0] == 3) // -
        {
            ai = 0;
            bi = 2;
        }

        if (vec[1] == 0) // backend
        {
            aj = 0;
            bj = 0;
        }
        else if (vec[1] == 1) // frontend
        {
            aj = 1;
            bj = 1;
        }
        else if (vec[1] == 3) // -
        {
            aj = 0;
            bj = 1;
        }

        if (vec[2] == 0) // junior
        {
            ak = 0;
            bk = 0;
        }
        else if (vec[2] == 1) // senior
        {
            ak = 1;
            bk = 1;
        }
        else if (vec[2] == 3) // -
        {
            ak = 0;
            bk = 1;
        }

        if (vec[3] == 0) // pizza
        {
            al = 0;
            bl = 0;
        }
        else if (vec[3] == 1) // chicken
        {
            al = 1;
            bl = 1;
        }
        else if (vec[3] == 3) // -
        {
            al = 0;
            bl = 1;
        }

        int temp_answer = 0;
        score = vec[4];

        for (int i = ai; i <= bi; i++)
        {
            for (int j = aj; j <= bj; j++)
            {
                for (int k = ak; k <= bk; k++)
                {
                    for (int l = al; l <= bl; l++)
                    {
                        int n = db[i][j][k][l].size();

                        if (n == 0) continue;

                        if (lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score) == db[i][j][k][l].end()) continue;
                        else temp_answer += n - (lower_bound(db[i][j][k][l].begin(), db[i][j][k][l].end(), score) - db[i][j][k][l].begin());
                    }
                }
            }
        }

        answer.push_back(temp_answer);
    }

    return answer;
}