#include<algorithm>
#include<iostream>
using namespace std;
/*DP문제
dfs로 풀면 시간초과 발생*/

int main() {
	int N, M;
	int map[1001][1001] = { 0, };
	int dp[1001][1001] = { 0, };
	int tmp[2][1001] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <=N; i++) 
		for (int j = 1; j <=M; j++) 
			cin >> map[i][j];
	dp[1][1] = map[1][1];
	//첫줄은 오른쪽으로 밖에 못움직이니까 미리 계산
	for (int i = 2; i <= M; i++) dp[1][i] += map[1][i] + dp[1][i - 1]; 


	for (int i = 2; i <= N; i++) {
		tmp[0][0] = dp[i - 1][1];//위에서 내려온 값
		for (int j = 1; j <= M; j++)//왼쪽에서 오른쪽으로 가는 경우
			tmp[0][j] = max(tmp[0][j - 1], dp[i - 1][j]) + map[i][j];//왼쪽에서 오는 경우와, 위에서 내려오는 경우 비교
		
		tmp[1][M + 1] = dp[i - 1][M]; //위에서 내려온 값
		for (int j = M; j >= 1; j--)
			tmp[1][j] = max(tmp[1][j + 1], dp[i - 1][j]) + map[i][j];//오른쪽에서 오는 경우와, 위에서 오는 경우를 비교
		
		for (int j = 1; j <= M; j++)
			dp[i][j] = max(tmp[0][j], tmp[1][j]);
	}
	cout << dp[N][M];
	return 0;
}