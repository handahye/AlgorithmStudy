#include <string>
#include <iostream>
using namespace std;
bool map[11][11];
int solution(string dirs)
{
     int answer = 0;
     int x = 5;
     int y = 5;
     map[x][y] = true;
     for (int i = 0; i < dirs.size(); i++)
     {
          char dir = dirs[i];
          // cout<<"dir: "<<dir<<"\n";
          if (dir == 'U')
          {
               int nx = x - 1;
               if (nx >= 1)
               {
                    if (!map[nx][y])
                    {
                         map[nx][y] = true;
                         answer++;
                    }
                    x = nx;
               }
          }
          else if (dir == 'D')
          {
               int nx = x + 1;
               if (nx <= 10)
               {
                    if (!map[nx][y])
                    {
                         map[nx][y] = true;
                         answer++;
                    }
                    x = nx;
               }
          }
          else if (dir == 'R')
          {
               int ny = y + 1;
               if (ny <= 10)
               {
                    if (!map[x][ny])
                    {
                         map[x][ny] = true;
                         answer++;
                    }
                    y = ny;
               }
          }
          else
          {
               int ny = y - 1;
               if (ny >= 1)
               {
                    if (!map[x][ny])
                    {
                         map[x][ny] = true;
                         answer++;
                    }
                    y = ny;
               }
          }
          // cout<<"x: "<<x<<" y: "<<y<<"\n";
          // cout<<"cnt: "<<answer<<"\n";
          // cout<<"---------------------\n";
     }
     if (answer != 0)
          return answer + 1;
     return answer;
}