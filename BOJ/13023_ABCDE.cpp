 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
int N, M;
vector<int> v[2001];
bool visit[2001];
bool End;
void dfs(int idx, int cnt) {
	if (End) return;
	if (cnt == 5) {
		End = true;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++) {
		int u = v[idx][i];
		if (!visit[u]) {
			visit[u] = true;
			dfs(u, cnt + 1);
			if (End) return;
			visit[u] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		visit[i] = true;
		dfs(i, 1);
		visit[i] = false;
	}
	printf("%d", End);
	return 0;
}