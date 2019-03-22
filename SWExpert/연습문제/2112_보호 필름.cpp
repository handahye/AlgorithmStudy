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
	for (int i = 0; i < W; i++) {
		int cnt = 1;
		for (int j = 0; j < D - 1; j++) {
			if (cnt == K) break;
			if (map[j][i] == map[j + 1][i]) cnt++;
			else cnt = 1;
		}
		if (cnt != K) return false;
	}
	return true;
}
void change(int r, int type) {
	for (int i = 0; i < W; i++) {
		map[r][i] = type;
	}
}
void dfs(int idx, int cnt) {
	if (cnt >= res) return;
	if (chk()) {
		res = min(res, cnt);
		return;
	}
	int tmp[21];
	for (int i = idx + 1; i < D; i++) {
		mapCopy(tmp, map[i]);
		for (int k = 0; k < 2; k++) {
			change(i, k);
			dfs(i, cnt + 1);
		}
		mapCopy(map[i], tmp);
	}
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
		dfs(-1, 0);
		printf("#%d %d\n", t, res);
	}
	return 0;
}
