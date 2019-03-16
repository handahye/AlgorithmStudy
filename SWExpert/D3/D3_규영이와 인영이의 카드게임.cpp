#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
int arr1[9], arr2[9];
bool visit[9];
int win, lose;
void dfs(int idx, int a, int b) {
	if (idx == 9) {
		if (a > b) win++;
		else lose++;
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (!visit[i]) {
			visit[i] = true;
			if (arr1[idx] > arr2[i]) dfs(idx + 1, a + (arr1[idx] + arr2[i]), b);
			else dfs(idx + 1, a, b + (arr1[idx] + arr2[i]));
			visit[i] = false;
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(visit, false, sizeof(visit));
		win = 0, lose = 0;
		bool chk[19] = { false, };
		for (int i = 0; i < 9; i++) {
			scanf("%d", &arr1[i]);
			chk[arr1[i]] = true;
		}
		for (int i = 1, k=0; i <= 18; i++) { 
			if (!chk[i]) arr2[k++] = i;
		}
		dfs(0, 0, 0);
		printf("#%d %d %d\n", t, win, lose);
	}
	return 0;
}