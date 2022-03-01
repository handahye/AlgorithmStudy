#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<string> map;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visit[4][510][510];
int changeDir(char c, int dir)
{
     if (c == 'L')
     {
          if (dir == 0)
               return 3;
          if (dir == 1)
               return 2;
          if (dir == 2)
               return 0;
          if (dir == 3)
               return 1;
     }
     else if (c == 'R')
     {
          if (dir == 0)
               return 2;
          if (dir == 1)
               return 3;
          if (dir == 2)
               return 1;
          if (dir == 3)
               return 0;
     }
}
int solve(int x, int y, int dir, int len)
{
     if (visit[dir][x][y])
          return len;
     visit[dir][x][y] = true;

     int ndir = dir;
     if (map[x][y] != 'S')
     {
          ndir = changeDir(map[x][y], dir);
     }
     int nx = x + dx[ndir];
     int ny = y + dy[ndir];

     if (nx < 0)
          nx = N - 1;
     if (ny < 0)
          ny = M - 1;
     if (nx == N)
          nx = 0;
     if (ny == M)
          ny = 0;

     return solve(nx, ny, ndir, len + 1);
}
vector<int> solution(vector<string> grid)
{
     vector<int> answer;
     N = grid.size();
     M = grid[0].length();
     map = grid;

     for (int i = 0; i < N; i++)
     {
          for (int j = 0; j < M; j++)
          {
               for (int d = 0; d < 4; d++)
               {
                    int res = solve(i, j, d, 0);
                    if (res != 0)
                    {
                         answer.push_back(res);
                    }
               }
          }
     }
     sort(answer.begin(), answer.end());
     return answer;
}