#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, unordered_set<string>> report_umap;
unordered_map<string, int> cnt_umap;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;

    for (int i = 0; i < report.size(); i++)
    {
        stringstream ss(report[i]);
        string token;

        vector<string> temp;

        while (getline(ss, token, ' '))
        {
            temp.push_back(token);
        }

        string id_1 = temp[0];
        string id_2 = temp[1];

        if (report_umap[id_1].count(id_2) == 0)
        {
            cnt_umap[id_2]++;
            report_umap[id_1].insert(id_2);
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        int result = 0;

        for (auto a : report_umap[id_list[i]])
        {
            if (cnt_umap[a] >= k) result++;
        }

        answer.push_back(result);
    }

    return answer;
}