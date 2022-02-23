#include <string>
#include <vector>
#include <math.h>
using namespace std;
char map[5][5][5];
int calDist(int x1, int y1, int x2, int y2)
{
     return abs(x1 - x2) + abs(y1 - y2);
}
vector<int> solution(vector<vector<string>> places)
{
     vector<int> answer;
     for (int i = 0; i < 5; i++)
     {
          vector<pair<int, int>> p;
          for (int j = 0; j < 5; j++)
          {
               for (int k = 0; k < 5; k++)
               {
                    if (places[i][j][k] == 'P')
                    {
                         p.push_back({j, k});
                    }
               }
          }
          if (p.size() == 0)
               answer.push_back(1);
          else
          {
               bool chk = false;
               for (int k = 0; k < p.size(); k++)
               {
                    for (int l = k + 1; l < p.size(); l++)
                    {
                         int x1 = p[k].first;
                         int y1 = p[k].second;
                         int x2 = p[l].first;
                         int y2 = p[l].second;
                         int dist = calDist(x1, y1, x2, y2);
                         if (dist <= 2)
                         {
                              if (x1 == x2)
                              { //세로로 같은 줄
                                   if (y1 < y2)
                                   {
                                        if (places[i][x1][y1 + 1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                                   else
                                   {
                                        if (places[i][x1][y2 + 1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                              }
                              else if (y1 == y2)
                              { //가로로 같은 줄
                                   if (x1 < x2)
                                   {
                                        if (places[i][x1 + 1][y1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                                   else
                                   {
                                        if (places[i][x2 + 1][y1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                              }
                              else
                              { //대각선
                                   if (x1 < x2 && y1 < y2)
                                   {
                                        if (places[i][x1 + 1][y1] != 'X' || places[i][x1][y1 + 1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                                   else if (x2 < x1 && y2 < y1)
                                   {
                                        if (places[i][x2 + 1][y2] != 'X' || places[i][x2][y2 + 1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                                   else if (x1 < x2 && y1 > y2)
                                   {
                                        if (places[i][x1][y2] != 'X' || places[i][x2][y1] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                                   else if (x2 < x1 && y2 > y1)
                                   {
                                        if (places[i][x2][y1] != 'X' || places[i][x1][y2] != 'X')
                                        {
                                             chk = true;
                                             break;
                                        }
                                   }
                              }
                         }
                    }
                    if (chk)
                         break;
               }
               if (!chk)
                    answer.push_back(1);
               else
                    answer.push_back(0);
          }
     }
     return answer;
}