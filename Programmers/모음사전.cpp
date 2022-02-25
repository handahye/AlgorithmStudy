#include <string>
#include <vector>
#include <map>

using namespace std;
int cnt = 1;
vector<string> v = {"A", "E", "I", "O", "U"};
map<string, int> m;
void dfs(string str)
{
     if (str.length() > 5)
          return;
     m[str] = cnt++;
     for (int i = 0; i < v.size(); i++)
     {
          dfs(str + v[i]);
     }
}
int solution(string word)
{
     int answer = 0;
     for (int i = 0; i < v.size(); i++)
     {
          dfs(v[i]);
     }
     return m[word];
}