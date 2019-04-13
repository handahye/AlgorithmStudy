 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
int res;
int N, M;
int map[101];
void bfs() {
	bool visit[101] = { false, };
	queue<pair<int,int>> q;
	q.push({ 1,0 });
	visit[1] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == 100) {
			res = min(res, cnt);
			continue;
		}
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next <= 100 && !visit[next]) {
				visit[next] = true;
				q.push({ map[next],cnt + 1 });
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d", &N, &M);
	res = 987654321;
	for (int i = 1; i <= 100; i++)
		map[i] = i;
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[x] = y;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		map[x] = y;
	}
	bfs();
	printf("%d", res);
	return 0;
}