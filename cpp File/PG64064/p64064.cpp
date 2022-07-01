#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool visited[10];

vector<string> uvec;
vector<string> bvec;

unordered_set<string> uset;

int cnt = 0;

bool check(string a, string b)
{
    if (a.length() != b.length()) return false;
    
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '*') continue;
        else if (a[i] != b[i]) return false;
    }
    
    return true;
}

void solve(int depth)
{
    if (depth == bvec.size())
    {
        string str = "";
        
        for (int i = 0; i < uvec.size(); i++)
        {
            if (visited[i])
            {
                str += (to_string(i) + "/");
            }
        }
        
        if (uset.count(str) == 0)
        {
            cnt++;
            uset.insert(str);
        }
        
        return;
    }
    
    for (int i = 0; i < uvec.size(); i++)
    {
        if (visited[i]) continue;
        
        if (check(uvec[i], bvec[depth]))
        {
            visited[i] = true;
            solve(depth + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    
    uvec = user_id;
    bvec = banned_id;
    
    solve(0);
    
    answer = cnt;
    
    return answer;
}