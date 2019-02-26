#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
using namespace std;
/*풀이 2*/
int N, ans;
bool col[15], d1[40], d2[40]; //열, /, \ 대각선
bool chk(int i, int j) {
	if (col[j] || d1[i + j] || d2[i - j + N]) return false;
	return true;
}
void dfs(int i) {
	if (i == N) {
		ans += 1;
		return;
	}
	for (int j = 0; j < N; j++) {
		if (chk(i, j)) {
			col[j] = d1[i + j] = d2[i - j + N] = true;
			dfs(i + 1);
			col[j] = d1[i + j] = d2[i - j + N] = false;
		}
	}
}
int main() {
	cin >> N;
	dfs(0);
	cout << ans << endl;
	return 0;
}
