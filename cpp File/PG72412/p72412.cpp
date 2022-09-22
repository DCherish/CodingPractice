#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> dp[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    
    for (int i = 0; i < info.size(); i++)
    {
        stringstream ss(info[i]);
        string token;
        
        vector<string> temp;
        
        while (getline(ss, token, ' '))
        {
            temp.push_back(token);
        }
        
        int a, b, c, d;
        
        if (temp[0] == "cpp") a = 0;
        else if (temp[0] == "java") a = 1;
        else if (temp[0] == "python") a = 2;
        
        if (temp[1] == "backend") b = 0;
        else if (temp[1] == "frontend") b = 1;
        
        if (temp[2] == "junior") c = 0;
        else if (temp[2] == "senior") c = 1;
        
        if (temp[3] == "chicken") d = 0;
        else if (temp[3] == "pizza") d = 1;
        
        dp[a][b][c][d].push_back(stoi(temp[4]));
    }
    
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            for (int c = 0; c < 2; c++)
            {
                for (int d = 0; d < 2; d++)
                {
                    sort(dp[a][b][c][d].begin(), dp[a][b][c][d].end());
                }
            }
        }
    }
    
    for (int i = 0; i < query.size(); i++)
    {
        stringstream ss(query[i]);
        string token;
        
        vector<string> temp;
        
        while (getline(ss, token, ' '))
        {
            if (token == "and") continue;
            
            temp.push_back(token);
        }
        
        int a1, a2, b1, b2, c1, c2, d1, d2;
        int score = stoi(temp[4]);
        
        if (temp[0] == "cpp")
        {
            a1 = 0;
            a2 = 0;
        }
        else if (temp[0] == "java")
        {
            a1 = 1;
            a2 = 1;
        }
        else if (temp[0] == "python")
        {
            a1 = 2;
            a2 = 2;
        }
        else
        {
            a1 = 0;
            a2 = 2;
        }
        
        if (temp[1] == "backend")
        {
            b1 = 0;
            b2 = 0;
        }
        else if (temp[1] == "frontend")
        {
            b1 = 1;
            b2 = 1;
        }
        else
        {
            b1 = 0;
            b2 = 1;
        }
        
        if (temp[2] == "junior")
        {
            c1 = 0;
            c2 = 0;
        }
        else if (temp[2] == "senior")
        {
            c1 = 1;
            c2 = 1;
        }
        else
        {
            c1 = 0;
            c2 = 1;
        }
        
        if (temp[3] == "chicken")
        {
            d1 = 0;
            d2 = 0;
        }
        else if (temp[3] == "pizza")
        {
            d1 = 1;
            d2 = 1;
        }
        else
        {
            d1 = 0;
            d2 = 1;
        }
        
        int result = 0;
        
        for (int a = a1; a <= a2; a++)
        {
            for (int b = b1; b <= b2; b++)
            {
                for (int c = c1; c <= c2; c++)
                {
                    for (int d = d1; d <= d2; d++)
                    {
                        int sz = dp[a][b][c][d].size();
                        
                        if (sz == 0) continue;
                        
                        result += (sz - (lower_bound(dp[a][b][c][d].begin(), dp[a][b][c][d].end(), score) - dp[a][b][c][d].begin()));
                    }
                }
            }
        }
        
        answer.push_back(result);
    }
    
    return answer;
}