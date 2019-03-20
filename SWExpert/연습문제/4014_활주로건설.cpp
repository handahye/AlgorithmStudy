#include <iostream>
#include<string.h>
using namespace std;
int map[21][21];
int N, X;
int res;
bool cal(int cur, int flag) {
	bool chk[21] = { false, };
	if (flag == 0) {
		for (int i = 0; i < N-1; i++) {
			if (map[cur][i] == map[cur][i+1]) continue;
			if (map[cur][i] == map[cur][i+1]+1) { //3->2인 경우
				i += 1;
				int cnt = 0;
				for (int j = 0; j < X; j++) {//현재부터 X개가 같은 숫잔지 
					if (i + j < N) {
						if (map[cur][i + j] == map[cur][i] && !chk[i+j]){
							chk[i + j] = true;
							cnt++;
						}
						
					}
				}
				if (cnt != X) return false;
			}
			else if (map[cur][i] +1== map[cur][i+1]) { //2->3인 경우
				int cnt = 0;
				for (int j = 0; j < X; j++) {
					if (i - j >= 0) {
						if (map[cur][i - j] == map[cur][i] && !chk[i - j]) {
							chk[i - j] = true;
							cnt++;
						}
					}
				}
				if (cnt != X) return false; 
			}
			else return false;
		}
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			if (map[i][cur] == map[i+1][cur]) continue;
			if(map[i][cur] == map[i + 1][cur] + 1) { //3->2인 경우
				i += 1;
				int cnt = 0;
				for (int j = 0; j < X; j++) {//현재부터 X개가 같은 숫잔지 
					if (i + j < N) {
						if (map[i + j][cur] == map[i][cur] && !chk[i+j]) {
							chk[i + j] = true;
							cnt++;
						}
					}
				}
				if (cnt != X) return false;
			}
			else if (map[i][cur] + 1 == map[i + 1][cur]) { //2->3인 경우
				int cnt = 0;
				for (int j = 0; j < X; j++) {
					if (i - j >= 0) {
						if (map[i - j][cur] == map[i][cur] && !chk[i - j]) {
							chk[i - j] = true;
							cnt++;
						}
					}
				}
				if (cnt != X) return false;
			}
			else return false;
		}
	}
	return true;
}
void dfs(int cur, int cnt, int flag) {
	if (cur == N) {
		res += cnt;
		return;
	}
	if (cal(cur, flag)) dfs(cur + 1, cnt + 1, flag);
	else dfs(cur + 1, cnt, flag);

}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		res = 0;
		scanf("%d%d", &N, &X);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		dfs(0, 0, 1);
		dfs(0, 0, 0);
		printf("#%d %d\n", t, res);
	}
	return 0;
}
