#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
vector<long long> solution(vector<long long> numbers)
{
     vector<long long> answer;
     for (int i = 0; i < numbers.size(); i++)
     {
          if (numbers[i] % 2 == 0)
          {
               answer.push_back(numbers[i] + 1);
          }
          else
          {
               long long bit = 1;
               while (1)
               {
                    if ((numbers[i] & bit) == 0)
                         break;
                    bit = bit << 1; // bit*=2;
               }
               bit = bit >> 1; // bit/=2;
               answer.push_back(numbers[i] + bit);
          }
     }
     return answer;
}