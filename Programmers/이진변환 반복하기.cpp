#include <string>
#include <vector>

using namespace std;
string toBinary(string str)
{
     int num = str.length();
     string res;
     while (num != 0)
     {
          res += (num % 2 == 0 ? "0" : "1");
          num /= 2;
     }
     return res;
}
vector<int> solution(string s)
{
     vector<int> answer(2);
     int cnt = 0, zeroCnt = 0;
     while (s.length() != 1)
     {
          string tmp = "";
          for (int i = 0; i < s.length(); i++)
          {
               if (s[i] == '1')
                    tmp += "1";
               else
                    zeroCnt++;
          }
          s = toBinary(tmp);
          cnt++;
     }
     answer[0] = cnt;
     answer[1] = zeroCnt;
     return answer;
}