#include<iostream>
#include<string.h>
using namespace std;
int T, N;
int score[101], dp[10001];//100점 * 100개 
int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		memset(dp, 0, sizeof(dp));
		int res = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
		}
		dp[0] = 1; 
		for (int i = 0; i < N;i++) {
			for (int j = sum; j >= 0; j--) {//0부터 sum까지 돌리면 누적해서 계산한 점수에 계속 갱신되니까
				if (dp[j]) dp[j + score[i]] = 1; //계산된 점수 + 현재 선택한 점수
			}
		}
		for (int i = 0; i <= sum; i++) 
			if (dp[i]) res++;
		printf("#%d %d\n", t, res);
	}
	return 0;
}
