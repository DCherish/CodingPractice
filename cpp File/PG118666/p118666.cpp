#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int arr[4];

unordered_map<char, int> umap;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    
    umap['R'] = 0;
    umap['T'] = 0;
    
    umap['C'] = 1;
    umap['F'] = 1;
    
    umap['J'] = 2;
    umap['M'] = 2;
    
    umap['A'] = 3;
    umap['N'] = 3;
    
    for (int i = 0; i < survey.size(); i++)
    {
        char A = survey[i][0];
        char B = survey[i][1];
        
        int idx = umap[A];
        int score = choices[i];
        
        if (score == 4) continue;
        
        if (A < B) arr[idx] += (score - 4);
        else arr[idx] += (4 - score);
    }
    
    if (arr[0] <= 0) answer += "R";
    else answer += "T";
    
    if (arr[1] <= 0) answer += "C";
    else answer += "F";
    
    if (arr[2] <= 0) answer += "J";
    else answer += "M";
    
    if (arr[3] <= 0) answer += "A";
    else answer += "N";
    
    return answer;
}