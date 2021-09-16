#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

char arr[10];
int num;
int maxcnt;
int len;

vector<char> vec;
map<string, int> info_si;
map<int, string> info_is;

void map_func()
{
    string s = "";
    vector<char> copy_vec = vec;

    sort(copy_vec.begin(), copy_vec.end());

    for (int i = 0; i < copy_vec.size(); i++)
    {
        s += copy_vec[i];
    }

    if (info_si.count(s) == 0) // info_si map 안에 s 라는 원소가 0개 있다면 ★★ // count "원소"의 개수
    {
        info_is[num] = s;
        num++;
    }

    info_si[s]++;

    if (info_si[s] > maxcnt)
    {
        maxcnt = info_si[s];
    }
}

void func(int idx, int cnt, string str)
{
    if (len == cnt)
    {
        map_func();

        return;
    }

    for (int i = idx; i < str.length(); i++)
    {
        vec.push_back(str[i]);
        func(i + 1, cnt + 1, str);
        vec.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < course.size(); i++)
    {
        len = course[i];

        maxcnt = 0;
        num = 1;

        info_si.clear();
        info_is.clear();

        for (int j = 0; j < orders.size(); j++)
        {
            func(0, 0, orders[j]);
        }

        for (int j = 1; j < num; j++)
        {
            if (info_si[info_is[j]] == maxcnt && info_si[info_is[j]] > 1)
            {
                answer.push_back(info_is[j]);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}