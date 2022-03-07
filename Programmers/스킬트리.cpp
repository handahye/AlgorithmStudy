#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees)
{
     int answer = 0;
     for (int i = 0; i < skill_trees.size(); i++)
     {
          bool fail = false;
          vector<bool> visit(skill.size(), false);
          for (int j = 0; j < skill_trees[i].size(); j++)
          {
               for (int k = 0; k < skill.size(); k++)
               {
                    if (skill_trees[i][j] == skill[k])
                    {
                         if (k != 0 && !visit[k - 1])
                         {
                              fail = true;
                              break;
                         }
                         visit[k] = true;
                    }
               }
          }
          if (!fail)
               answer++;
     }
     return answer;
}