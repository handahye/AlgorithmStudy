#include <iostream>
#include <queue>
#include <string.h>
#include<algorithm>
using namespace std;
/*dp + dfs*/
struct que {
	int r, c, s, cnt;
};
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, K;
int map[501][501];
int dp[501][501];
int dfs(int r, int c) {
	if (dp[r][c]) return dp[r][c];

	dp[r][c] = 1;

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d], nc = c + dc[d];
		if (nr > 0 && nc > 0 && nr <= N && nc <= N) {
			if (map[r][c] < map[nr][nc]) {
				dp[r][c] = max(dfs(nr, nc) + 1, dp[r][c]);
			}
		}
	}
	return dp[r][c];
}
int main() {
	scanf("%d", &N);
	K = -987654321;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			K = max(K, dfs(i, j));
		}
	}
	
	printf("%d\n", K);
}