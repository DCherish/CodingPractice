#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<char, int> umap;
int result[5];

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    
    umap['R'] = 1;
    umap['T'] = 1;
    
    umap['C'] = 2;
    umap['F'] = 2;
    
    umap['J'] = 3;
    umap['M'] = 3;
    
    umap['A'] = 4;
    umap['N'] = 4;
    
    int sz = survey.size();
    
    for (int i = 0; i < sz; i++)
    {
        char A = survey[i][0];
        char B = survey[i][1];
        
        int idx = umap[A];
        int score = choices[i] - 4;
        
        if (A > B) score *= -1;
        // else if (A < B) { // do nothing... }
        
        result[idx] += score;
    }
    
    if (result[1] <= 0) answer += "R";
    else answer += "T";
    
    if (result[2] <= 0) answer += "C";
    else answer += "F";
    
    if (result[3] <= 0) answer += "J";
    else answer += "M";
    
    if (result[4] <= 0) answer += "A";
    else answer += "N";
    
    return answer;
}