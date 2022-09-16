#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct info
{
    int score;
    char bonus;
    int option;
};

vector<info> vec;

int solution(string dartResult)
{
    int answer = 0;
    
    for (int i = 0; i < dartResult.length();)
    {
        string score = "";
        
        while (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            score += dartResult[i];
            i++;
        }
        
        char bonus = dartResult[i];
        i++;
        
        int option = 0;
        
        if (dartResult[i] == '*')
        {
            option = 1;
            i++;
        }
        else if (dartResult[i] == '#')
        {
            option = 2;
            i++;
        }
        
        vec.push_back({ stoi(score), bonus, option });
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        int idx = 1;
        
        if (vec[i].bonus == 'D') idx = 2;
        else if (vec[i].bonus == 'T') idx = 3;
        
        vec[i].score = pow(vec[i].score, idx);
        
        if (vec[i].option == 1)
        {
            if (i != 0) vec[i - 1].score *= 2;
            
            vec[i].score *= 2;
        }
        else if (vec[i].option == 2)
        {
            vec[i].score *= -1;
        }
    }
    
    for (int i = 0; i < vec.size(); i++)
    {
        answer += vec[i].score;
    }
        
    return answer;
}