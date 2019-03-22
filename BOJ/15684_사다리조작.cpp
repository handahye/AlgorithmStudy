#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int H, N, M;
int map[32][12];
int res;
bool chk() {
	for (int j = 1; j < N; j++){
		int r=1, c = j;
		while (1){
			if (r > H){
				if (c == j) break;
				else return false;
			}
			if (map[r][c]==0) r++;
			else if (map[r][c] == 1) r++, c++;
			else if (map[r][c] == 2) r++, c--;
		}
	}
	return true;
}
void dfs(int cnt, int h, int n) {
	if (cnt > 3||res<cnt) return;
	if (chk()) {
		res = min(res, cnt);
		return;
	}
	for (int i = h; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				map[i][j + 1] = 2;
				dfs(cnt + 1, i, j);
				map[i][j] = 0;
				map[i][j + 1] = 0;
			}
		}
	}
}
int main() {
	res = 987654321;
	scanf("%d%d%d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}
	dfs(0,1,1);
	if (res == 987654321) printf("-1\n");
	else printf("%d\n",res);
	return 0;
}
