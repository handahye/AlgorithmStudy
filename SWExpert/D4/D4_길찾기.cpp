#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
bool End;
int T, N;

bool visit[100];
void dfs(int cur, vector<int> map[]) {
	if (End) return;
	if (cur == 99) {
		End = true;
		return;
	}
	for (int i = 0; i < map[cur].size(); i++) {
		int next = map[cur][i];
		if (!visit[next]) {
			visit[next] = true;
			dfs(next,map);
			visit[next] = false;
		}
	}
}
int main() {
	for (int t = 1;t <= 10; t++) {
		scanf("%d %d", &T, &N);
		End = false;
		memset(visit, false, sizeof(visit));
		vector<int> map[100];
		for (int i = 0; i < N; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			map[u].push_back(v);
		}
		visit[0] = true;
		dfs(0, map);
		if(End) printf("#%d 1\n", t);
		else printf("#%d 0\n", t);
	}
	return 0;
}