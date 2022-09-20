#include <string>
#include <vector>

using namespace std;

string s[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

int N;

string cnvert(int num)
{
    if (num < N) return s[num];
    
    int front = num / N;
    int back = num % N;
    
    return cnvert(front) + cnvert(back);
}

// string cnvert(int num)
// {
//     string result = "";
    
//     while (num / N != 0)
//     {
//         string temp = result;
//         result = s[num % N];
//         result += temp;
        
//         num /= N;
//     }
    
//     string temp = result;
//     result = s[num % N];
//     result += temp;
    
//     return result;
// }

string solution(int n, int t, int m, int p)
{
    string answer = "";
    
    N = n;
    
    int num = 0;
    int idx = 1;
    
    while (true)
    {
        string str = cnvert(num);
        
        for (int i = 0; i < str.length(); i++)
        {
            if (idx == p) answer += str[i];
            
            idx++;
            
            if (idx > m) idx = 1;
            
            if (answer.length() == t) return answer;
        }
        
        num++;
    }
    
    return answer;
}