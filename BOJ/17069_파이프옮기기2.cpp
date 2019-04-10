#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N;
int map[33][33];
long long dp[33][33][3];
long long res = 0;
int dr[] = { 0,1,1 };
int dc[] = { 1,0,1 };
bool wallChk(int r, int c, int d){
	if (d == 0) {
		if(map[r][c + 1]) return false;
	}
	else if (d == 1) {
		if (map[r + 1][c]) return false;
	}
	else if (d == 2) {
		if (map[r][c + 1] || map[r + 1][c] || map[r + 1][c + 1]) return false;
	}
	return true;
}
long long dfs(int r, int c, int dir) {
	if (dp[r][c][dir] != -1) return dp[r][c][dir];
	if (r == N && c == N) return 1;
	dp[r][c][dir] = 0;

	for (int d = 0; d < 3; d++) {
		if (dir == 0 && d == 1) continue;
		if (dir == 1 && d == 0) continue;
		int nr = r + dr[d], nc = c + dc[d];
		if (nr <= N && nc <= N) {
			if (wallChk(r, c, d)) {
				dp[r][c][dir] = dp[r][c][dir] + dfs(nr, nc, d);
			}
		}
	}
	return dp[r][c][dir];
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld", dfs(1, 2, 0));
	return 0;
}