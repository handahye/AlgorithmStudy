#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
vector<int> map[101];
bool visit[101] = {
    false,
};
bool adj[101][101] = {
    false,
};
int cnt = 0;
void dfs(int u)
{
     for (int i = 0; i < map[u].size(); i++)
     {
          int v = map[u][i];
          if (adj[u][v] || adj[v][u])
               continue;
          if (visit[v])
               continue;
          visit[v] = true;
          cnt++;
          dfs(v);
          visit[v] = false;
     }
}
int solution(int n, vector<vector<int>> wires)
{
     int answer = 987654321;
     for (int i = 0; i < wires.size(); i++)
     {
          map[wires[i][0]].push_back(wires[i][1]);
          map[wires[i][1]].push_back(wires[i][0]);
     }
     for (int u = 1; u <= n; u++)
     {
          for (int j = 0; j < map[u].size(); j++)
          {
               int v = map[u][j];
               if (map[u].size() == 1)
               {
                    answer = min(answer, n - 1);
               }
               else
               {
                    adj[u][v] = adj[v][u] = true; //연결 끊기
                    visit[u] = true;
                    cnt = 1;
                    dfs(u);
                    visit[u] = false;
                    adj[u][v] = adj[v][u] = false; //다시 연결

                    answer = min(answer, abs((n - cnt) - cnt));
               }
          }
     }
     return answer;
}