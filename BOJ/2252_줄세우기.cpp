#include <iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
BOJ_2252_줄세우기
: 위상정렬
*/
vector<int> map[32002];
stack <int> s;
bool visit[32002];
void dfs(int idx) {
	for (int i = 0; i < map[idx].size(); i++) {
		if (!visit[map[idx][i]]) {
			visit[map[idx][i]] = 1;
			dfs(map[idx][i]);
		}
	}
	s.push(idx);
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		map[u].push_back(v);
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}