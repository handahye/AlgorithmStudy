#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct egg {
	int s, w;
};
int N;
vector<egg>v;
int maxN = 0;
bool visit[9][301];
int breakEgg(int a, int b) {
	int cnt = 0;
	v[a].s -= v[b].w;
	v[b].s -= v[a].w;
	if (v[a].s <= 0) cnt++;
	if (v[b].s <= 0) cnt++;
	return cnt;
}
void dfs(int cur, int cnt) {
	if (cur == N) {
		maxN = max(maxN, cnt);
		return;
	}
	if (v[cur].s <= 0 || cnt == N - 1) {
		dfs(cur + 1, cnt);
		return;
	}
	vector<egg> tmp = v;
	for (int i = 0; i < v.size(); i++) {
		if (i == cur || v[i].s <= 0) continue;
		if (!visit[cur][i]) {
			visit[cur][i] = true;
			int count = breakEgg(i, cur);
			dfs(cur + 1, cnt + count);
			visit[cur][i] = false;
			v = tmp;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s, w;
		scanf("%d %d", &s, &w);
		v.push_back({ s,w });
	}
	visit[0][0] = true;
	dfs(0, 0);
	printf("%d\n", maxN);
	return 0;
}