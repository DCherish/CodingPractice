#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_set>
#include <iostream>

using namespace std;
typedef long long ll;

int minX = INT_MAX;
int maxX = INT_MIN;

int minY = INT_MAX;
int maxY = INT_MIN;

unordered_set<string> uset;

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    
    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            ll A = (ll)line[i][0];
            ll B = (ll)line[i][1];
            ll E = (ll)line[i][2];
            
            ll C = (ll)line[j][0];
            ll D = (ll)line[j][1];
            ll F = (ll)line[j][2];
            
            ll valid = A * D - B * C;
            
            if (valid == 0) continue;
            else
            {
                ll bfed = (B * F - E * D);
                ll ecaf = (E * C - A * F);
                
                if (bfed % valid == 0 && ecaf % valid == 0)
                {
                    int x = (int)(bfed / valid);
                    int y = (int)(ecaf / valid);
                    
                    minX = min(minX, x);
                    maxX = max(maxX, x);
                    
                    minY = min(minY, y);
                    maxY = max(maxY, y);
                    
                    string s = to_string(x) + "/" + to_string(y);
                    
                    uset.insert(s);
                }
            }
        }
    }
    
    for (int i = maxY; i >= minY; i--)
    {
        string str = "";
        
        for (int j = minX; j <= maxX; j++)
        {
            string temp = to_string(j) + "/" + to_string(i);
            
            if (uset.count(temp) != 0)
            {
                str += "*";
            }
            else
            {
                str += ".";
            }
        }
        
        answer.push_back(str);
    }
    
    return answer;
}