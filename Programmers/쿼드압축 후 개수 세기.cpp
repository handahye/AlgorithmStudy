#include <string>
#include <vector>
#include <queue>
using namespace std;
int N;
struct node
{
     int x, y, n;
};
vector<int> solution(vector<vector<int>> arr)
{
     vector<int> answer(2, 0);
     N = arr.size();
     queue<node> q;
     q.push({0, 0, N});
     while (!q.empty())
     {
          int x = q.front().x;
          int y = q.front().y;
          int n = q.front().n;
          q.pop();

          if (x + n > N || y + n > N)
               continue;

          int num = arr[x][y];
          bool fail = false;
          for (int i = x; i < x + n; i++)
          {
               for (int j = y; j < y + n; j++)
               {
                    if (i == x && j == y)
                         continue;
                    if (num != arr[i][j])
                    {
                         fail = true;
                         break;
                    }
               }
          }
          if (fail && n != 1)
          {
               q.push({x, y, n / 2});
               q.push({x + (n / 2), y, n / 2});
               q.push({x, y + (n / 2), n / 2});
               q.push({x + (n / 2), y + (n / 2), n / 2});
          }
          else
          {
               answer[num]++;
          }
     }
     return answer;
}