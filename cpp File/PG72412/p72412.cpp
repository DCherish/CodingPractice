#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> db[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    
    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);
        string token;
        
        vector<int> vec;
        
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

        int a1, a2, b1, b2, c1, c2, d1, d2, score;

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
            a1 = 0;
            a2 = 0;
        }
        else if (vec[0] == 1) // python
        {
            a1 = 1;
            a2 = 1;
        }
        else if (vec[0] == 2) // cpp
        {
            a1 = 2;
            a2 = 2;
        }
        else if (vec[0] == 3) // -
        {
            a1 = 0;
            a2 = 2;
        }

        if (vec[1] == 0) // backend
        {
            b1 = 0;
            b2 = 0;
        }
        else if (vec[1] == 1) // frontend
        {
            b1 = 1;
            b2 = 1;
        }
        else if (vec[1] == 3) // -
        {
            b1 = 0;
            b2 = 1;
        }

        if (vec[2] == 0) // junior
        {
            c1 = 0;
            c2 = 0;
        }
        else if (vec[2] == 1) // senior
        {
            c1 = 1;
            c2 = 1;
        }
        else if (vec[2] == 3) // -
        {
            c1 = 0;
            c2 = 1;
        }

        if (vec[3] == 0) // pizza
        {
            d1 = 0;
            d2 = 0;
        }
        else if (vec[3] == 1) // chicken
        {
            d1 = 1;
            d2 = 1;
        }
        else if (vec[3] == 3) // -
        {
            d1 = 0;
            d2 = 1;
        }

        score = vec[4];
        
        int temp = 0;

        for (int a = a1; a <= a2; a++)
        {
            for (int b = b1; b <= b2; b++)
            {
                for (int c = c1; c <= c2; c++)
                {
                    for (int d = d1; d <= d2; d++)
                    {
                        int n = db[a][b][c][d].size();

                        if (n == 0) continue;

                        if (lower_bound(db[a][b][c][d].begin(), db[a][b][c][d].end(), score) == db[a][b][c][d].end()) continue;
                        else temp += n - (lower_bound(db[a][b][c][d].begin(), db[a][b][c][d].end(), score) - db[a][b][c][d].begin());
                    }
                }
            }
        }

        answer.push_back(temp);
    }

    return answer;
}