#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right)
{
     vector<int> answer;
     int sx = ceil(left / n);
     int sy = left % n;
     int ex = ceil(right / n);
     int ey = right % n;
     for (int x = sx; x <= ex; x++)
     {
          for (int y = 0; y < n; y++)
          {
               if (x == sx && y < sy)
                    continue;
               if (x == ex && y > ey)
                    continue;
               if (x > y)
               {
                    answer.push_back(x + 1);
               }
               else if (x <= y)
               {
                    answer.push_back(y + 1);
               }
          }
     }
     return answer;
}