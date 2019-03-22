#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int map[14][21];
int D, W, K;
int res;
void mapCopy(int a[], int b[]) {
	for (int i = 0; i < W; i++)
		a[i] = b[i];
}
bool chk() {
	int cnt = 1;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < D-1; j++) {
			if (cnt == K) break;
			if (map[j][i] == map[j + 1][i]) cnt++;
			else cnt = 1;
		}
		if (cnt != K) return false;
	}
	return true;
}
void dfs(int idx, int cnt) {
	if (cnt > res) return;

	if (chk()) {
		res = min(res, cnt);
		return;
	}
	for (int i = idx + 1; i < D; i++) {

	}
}
void change(int r) {

}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		res = 987654321;
		scanf("%d%d%d", &D, &W, &K);
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				scanf("%d", &map[i][j]);
		if(chk()) printf("#%d 0\n", t);
		else {
			for (int i = 0; i < D; i++)
				dfs(i, 0);
		}
	}
	return 0;
}
