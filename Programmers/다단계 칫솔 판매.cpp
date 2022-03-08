#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> answer(100001, 0);
vector<string> v;
map<string, int> m;
void dfs(string s, int money, int cnt)
{
     int idx = m[s];
     string rec = v[idx];
     if (rec == "-")
     {
          if (money >= 10)
          {
               answer[idx] += ceil((float)money * 0.9);
          }
          else
          {
               answer[idx] += money;
          }
          return;
     }
     else
     {
          if (money >= 10)
          {
               answer[idx] += ceil((float)money * 0.9);
               dfs(rec, float(money) * 0.1, cnt + 1);
          }
          else
          {
               answer[idx] += money;
          }
     }
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
     for (int i = 0; i < enroll.size(); i++)
     {
          m.insert({enroll[i], i});
          v.push_back(referral[i]);
     }
     for (int i = 0; i < seller.size(); i++)
     {
          dfs(seller[i], amount[i] * 100, 0);
     }
     vector<int> res;
     for (int i = 0; i < enroll.size(); i++)
          res.push_back(answer[i]);
     return res;
}