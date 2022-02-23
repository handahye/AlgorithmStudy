#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int n1, int n2)
{
    return n1 > n2;
}
string solution(string s)
{
    string answer = "";
    vector<int> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s.at(i));
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        answer += char(v[i]);
    }
    return answer;
}