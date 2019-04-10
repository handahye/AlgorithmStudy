#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
struct que {
	int idx, i, time;
};
int N, k;
int map[2][100001];
bool visit[2][100001];
bool bfs() {
	bool End = false;
	queue<que>q;
	q.push({ 0,0,0 });
	visit[0][0] = true;
	while (!q.empty() && !End) {
		int idx = q.front().idx;
		int i = q.front().i;
		int time = q.front().time;
		q.pop();
		if (time >= N) break;

		if (i+1 >= N || i+k >=N) End = true;
		if (i+1 > time && i+1 < N) {
			if (map[idx][i+1] == 1 && !visit[idx][i+1]) {
				visit[idx][i + 1] = true;
				q.push({ idx, i + 1, time + 1 });
			}
		}
		if (i - 1 > time && i - 1 < N) {
			if (map[idx][i - 1] == 1 && !visit[idx][i - 1]) {
				visit[idx][i - 1] = true;
				q.push({ idx, i - 1, time + 1 });
			}
		}
		if (i + k > time && i + k < N) {
			int tmp = idx == 0 ? 1 : 0;
			if (map[tmp][i + k] == 1 && !visit[tmp][i + k]) {
				visit[tmp][i + k] = true;
				q.push({ tmp, i + k, time + 1 });
			}
		}
		
	}
	return End;
}
int main() {
	scanf("%d%d",&N,&k);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	if (bfs()) printf("1");
	else printf("0");
	return 0;
}