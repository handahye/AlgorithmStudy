#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int N, M;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int map[1001][1001];
int visit[1001][1001];
int res;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if (c == 'S') map[i][j] = 2;
			else if (c == 'N') map[i][j] = 3;
			else if (c == 'E') map[i][j] = 0;
			else if (c == 'W') map[i][j] = 1;
		}
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				int r = i, c = j;
				while (visit[r][c] == 0) {
					visit[r][c] = cnt;
					int d = map[r][c];
					r += dr[d], c += dc[d];
				}
				if (visit[r][c] == cnt) res++;
				cnt++;
			}
		}
	}
	printf("%d", res);
	return 0;
}