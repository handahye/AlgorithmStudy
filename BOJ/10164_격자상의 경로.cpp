#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N, M, K;
int map[16][16];
int dp[16][16];
int dr[] = { 0,1 };
int dc[] = { 1,0 };
int er, ec;
int dfs(int r, int c, int er, int ec) {
	if (dp[r][c] != 0) return dp[r][c];
	if (r == er && c == ec) return 1;
	for (int d = 0; d < 2; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if(nr <= N && nc <= M) {
			dp[r][c] = dp[r][c] + dfs(nr, nc, er, ec);
		}
	}
	return dp[r][c];
}
int main() {
	scanf("%d%d%d", &N, &M, &K);
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = num;
			num++;
		}
	}
	if (K == 0) {
		printf("%d",dfs(0, 0, N - 1, M - 1));
	}
	else {
		K--;
		int r = K / M;
		int c = K % M;
		int res = dfs(0, 0, r, c);
		memset(dp, 0, sizeof(dp));
		res *= dfs(r, c, N - 1, M - 1);
		printf("%d", res);
	}
	return 0;
}