#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    double start;
    double end;
};

int solution(vector<string> lines) {
    int answer = 0;

    vector<info> vec;

    for (int i = 0; i < lines.size(); i++)
    {
        string str = lines[i];

        double h = stod(str.substr(11, 2)) * 3600;
        double m = stod(str.substr(14, 2)) * 60;
        double s = stod(str.substr(17, 6));

        double endT = h + m + s;
        double process = stod(str.substr(24, 5));

        double srtT = endT - process + 0.001;

        vec.push_back({srtT, endT});
    }

    for (int i = 0; i < vec.size(); i++)
    {
        double tempS = vec[i].start;
        double tempE = vec[i].end;

        int cnt = 1;

        for (int j = i + 1; j < vec.size(); j++)
        {
            if (tempE + 1 > vec[j].start)
            {
                cnt++;
            }
        }

        answer = max(answer, cnt);
    }

    return answer;
}