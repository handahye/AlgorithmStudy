#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dp[100001][4]; //고유번호, 품종
int num[100001];
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("#%d\n", t);
		int N, Q;
		scanf("%d %d", &N, &Q);
		for (int i = 1; i <= N; i++) 
			scanf("%d", &num[i]);
		//그 전의 번호까지 센 각각의 품종 갯수들 + 지금 내 품종 
		for (int i = 1; i <= N; i++) {
			num[i] == 1 ? dp[i][1] = dp[i - 1][1] + 1 : dp[i][1] = dp[i - 1][1];
			num[i] == 2 ? dp[i][2] = dp[i - 1][2] + 1 : dp[i][2] = dp[i - 1][2];
			num[i] == 3 ? dp[i][3] = dp[i - 1][3] + 1 : dp[i][3] = dp[i - 1][3];
		}
		for (int i = 0; i < Q; i++) {
			int L, R;
			scanf("%d%d", &L, &R);
			int a = dp[R][1] - dp[L-1][1];
			int b = dp[R][2] - dp[L-1][2];
			int c = dp[R][3] - dp[L-1][3];
			printf("%d %d %d\n", a, b, c);
		}
	}
	return 0;
}