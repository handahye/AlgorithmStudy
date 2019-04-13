 #include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<queue>
using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int N, M, A, B, K;
int map[501][501];
bool visit[501][501];
int sr, sc, er, ec;
bool chk(int r, int c, int d) {
	if (d == 0) {
		int nc = c + B; 
		if (nc <= M) {
			for (int i = 0; i < A; i++) {
				if (map[r + i][nc] == 1) return false;
			}
		}
		else return false;
	}
	else if (d == 1) {
		int nc = c - 1;
		if (nc > 0) {
			for (int i = 0; i < A; i++) {
				if (map[r + i][nc]) return false;
			}
		}
		else return false;

	}
	else if (d == 2) {
		int nr = r + A;
		if (nr <= N) {
			for (int i = 0; i < B; i++) {
				if (map[nr][c + i] == 1)return false;
			}
		}
		else return false;
	}
	else if (d == 3) {
		int nr = r - 1;
		if (nr > 0) {
			for (int i = 0; i < B; i++) {
				if (map[nr][c + i] == 1)return false;
			}
		}
		else return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d%d%d%d%d", &N, &M, &A, &B, &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = 1;
	}
	scanf("%d%d%d%d", &sr, &sc, &er, &ec);
	queue<pair<int,pair<int, int>>>q;
	q.push({ 0,{sr,sc } });
	visit[sr][sc] = true;
	int res = 987654321;
	while (!q.empty()) {
		int cnt = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		if (r == er && c == ec) {
			res = min(res, cnt);
			continue;
		}
		for (int d = 0; d < 4; d++) {
			if (chk(r, c, d)) {
				int nr = r + dr[d], nc = c + dc[d];
				if (!visit[nr][nc]) {
					visit[nr][nc] = true;
					q.push({ cnt + 1,{nr,nc } });
				}
			}
		}


	}
	if (res == 987654321) printf("-1");
	else printf("%d", res);
	return 0;
}