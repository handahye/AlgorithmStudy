#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int answer;
int visit[51];
void dfs(int cnt, string cur, string target, vector<string> words){
    if(words.size()<cnt){
        return;
    }
    if(cur==target){
        answer = min(answer, cnt);
        return;
    }
    for(int i=0; i<words.size(); i++){
        int len = 0;
        if(visit[i]) continue;
        for(int j=0; j<words[i].size(); j++){
            if(cur[j]==words[i][j]) len++;
        }
        if(len==words[i].size()-1){
            visit[i] = 1;
            dfs(cnt+1, words[i],target,words);
            visit[i] = 0;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    answer = 987654321;
    memset(visit,0,sizeof(visit));
    dfs(0, begin, target, words);
    if(answer==987654321) return 0;
    else return answer;
}