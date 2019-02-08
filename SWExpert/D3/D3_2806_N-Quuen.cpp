#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
int visit[11];
int N, ans;
bool chk(int i) {
	for (int j = 0; j < i; j++) {//0부터 현재 행까지 
		if (visit[j] == visit[i] || abs(visit[i] - visit[j]) == (i - j)) 
			return false;
	}
	return true;
}
void dfs(int cnt) {
	if (cnt == N) { //N개를 모두 센 경우
		ans += 1;
		return;
	}
	for (int i = 0; i < N; i++) { //다음위치 찾기
		visit[cnt] = i; 
		if (chk(cnt)) //현재 자리에 퀸을 놓을 수 있는지
			dfs(cnt + 1);
	}
}
int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(visit, 0, sizeof(visit));
		cin >> N;
		ans = 0;
		dfs(0);
		cout << "#"<<t<<" " <<ans << endl;
	}
	return 0;
}