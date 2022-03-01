#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool chk(string str)
{
     stack<char> s;
     for (int i = 0; i < str.length(); i++)
     {
          if (str[i] == '(' || str[i] == '{' || str[i] == '[')
          {
               s.push(str[i]);
          }
          else
          {
               if (s.size() == 0)
                    return false;
               char c = s.top();
               bool flag = false;
               if (str[i] == ')' && c == '(')
               {
                    flag = true;
               }
               else if (str[i] == ']' && c == '[')
               {
                    flag = true;
               }
               else if (str[i] == '}' && c == '{')
               {
                    flag = true;
               }

               if (flag)
                    s.pop();
               else
                    return false;
          }
     }

     if (s.size() != 0)
          return false;
     else
          return true;
}
int solution(string s)
{
     int answer = 0;
     for (int i = 0; i < s.length(); i++)
     {
          string str;
          if (i != 0)
               str = s.substr(i) + s.substr(0, i);
          else
               str = s;
          if (chk(str))
          {
               answer++;
          }
     }
     return answer;
}