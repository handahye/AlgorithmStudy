#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = -1;
bool visit[8] = {
    false,
};
void dfs(int k, vector<vector<int>> &v, int cnt)
{
     answer = max(answer, cnt);
     for (int i = 0; i < v.size(); i++)
     {
          if (!visit[i] && k >= v[i][0])
          {
               visit[i] = true;
               // cout<<"k: "<<k-v[i][1]<<" idx: "<<i<<" cnt: "<<cnt<<"\n";
               dfs(k - v[i][1], v, cnt + 1);
               visit[i] = false;
          }
     }
}
int solution(int k, vector<vector<int>> dungeons)
{
     dfs(k, dungeons, 0);
     return answer;
}