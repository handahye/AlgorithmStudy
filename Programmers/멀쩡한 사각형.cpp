#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int &w, int &h)
{
     int c;
     while (h != 0)
     {
          c = w % h;
          w = h;
          h = c;
     }
     // h==0 이라면 w%h==0 인거니까 f(w,h)=w
     return w;
}
long long solution(int w, int h)
{
     long long answer = 1;
     //((w/최대공약수)+(h/최대공약수))*최대공약수 = (w+h-최대공약수)
     // (w*h) - (w+h-최대공약수)
     answer = (long long)w * (long long)h - (w + h);
     answer += gcd(w, h);
     return answer;
}