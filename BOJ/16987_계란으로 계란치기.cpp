#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct egg {
	int s, w;
	bool chk;
};
int N;
vector<egg>v;
int maxN = 0;
bool visit[9][301];
int countBreak() {
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].chk) res++;
	}
	return res;
}
void breakEgg(int a, int b) {
	v[a].s -= v[b].w;
	v[b].s -= v[a].w;

	if (v[a].s <= 0) v[a].chk = true;
	if (v[b].s <= 0) v[b].chk = true;
}
int nextEgg(int cur) {
	bool chk = false;
	for (int i = cur + 1; i < N; i++) {
		if (!v[i].chk) {
			visit[i][i] = true;
			return i;
		}
	}
	if (!chk) {
		maxN = max(maxN, countBreak());
		return -1;
	}
}
void dfs(int cur) {
	if (cur == -1) {
		maxN = max(maxN, countBreak());
		return;
	}
	if (cur == v.size() - 1) {
		for (int i = 0; i < v.size(); i++) {
			vector<egg> tmp = v;
			if (i == cur) continue;
			if (!v[i].chk) {
				breakEgg(cur, i);
				maxN = max(maxN, countBreak());
				v = tmp;
			}
		}
		return;			
	}
	vector<egg> tmp = v;
	for (int i = 0; i < v.size(); i++) {
		if (i == cur) continue;
		if (!visit[cur][i]) {
			visit[cur][i] = true;
			if(!v[i].chk) breakEgg(cur, i); 
			int next = nextEgg(cur);
			dfs(next);
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
		v.push_back({ s,w, false });
	}
	visit[0][0] = true;
	dfs(0);
	printf("%d\n", maxN);
	return 0;
}