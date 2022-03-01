#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
list<char> DtoB(long long number)
{
     list<char> c;
     while (number > 0)
     {
          c.push_back(number % 2);
          number /= 2;
     }
     reverse(c.begin(), c.end());
     return c;
}
vector<long long> solution(vector<long long> numbers)
{
     vector<long long> answer;
     for (int i = 0; i < numbers.size(); i++)
     {
          list<char> cur = DtoB(numbers[i]);
          long long nextNum = numbers[i] + 1;
          while (1)
          {
               long long diff = 0;
               list<char> next = DtoB(nextNum);
               if (cur.size() != next.size())
                    cur.push_front('0');
               list<char>::iterator iter1, iter2;
               for (iter1 = cur.begin(), iter2 = next.begin(); iter1 != cur.end(); ++iter1, ++iter2)
               {
                    if (*iter1 != *iter2)
                         diff++;
               }
               if (diff <= 2)
                    break;
               nextNum++;
          }
          answer.push_back(nextNum);
     }
     return answer;
}