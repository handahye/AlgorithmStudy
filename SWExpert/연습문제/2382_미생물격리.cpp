#include <iostream>
#include <queue>
#include <string.h>
#include<algorithm>
using namespace std;
struct st {
	int r;
	int c;
	long long num;
	int dir;
};
int N, M, K;
int dr[] = { 0, -1,1,0,0 };
int dc[] = { 0, 0,0,-1,1 };
vector<st> v;
int dirChange(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else return 3;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &N, &M, &K);
		v.clear();
		for (int i = 0; i < K; i++) {
			int r, c, dir;
			long long num;
			scanf("%d%d%lld%d", &r, &c, &num, &dir);
			v.push_back({ r,c,num,dir });
		}
		while (M--) {
			vector<st> alive;
			int map[102][102] = { 0, };
			long long tmp[102][102][3] = { 0, }; //0: sum, 1: dir, 2: num
			vector<pair<int, int>> chk;
			int chk2[102][102] = { 0, };
			for (int i = 0; i < v.size(); i++) {
				int d = v[i].dir;
				long long num = v[i].num;
				int nr = v[i].r + dr[d], nc = v[i].c + dc[d];
				if (nr == 0 || nc == 0 || nr == N - 1 || nc == N - 1) {
					num /= 2;
					if (num > 0) {
						d = dirChange(d);
						alive.push_back({ nr,nc,num,d });
					}
				}
				else {
					if (!chk2[nr][nc]) {
						chk2[nr][nc] = true;
						chk.push_back({ nr,nc });
					}
					map[nr][nc] += 1;
					tmp[nr][nc][0] += num;
					if (map[nr][nc] == 1) { //미생물이 아직 없는 경우
						tmp[nr][nc][1] = d;
						tmp[nr][nc][2] = num;
					}
					if (map[nr][nc]> 1) { //미생물이 있는 경우
						if (tmp[nr][nc][2] < num) {
							tmp[nr][nc][2] = num;
							tmp[nr][nc][1] = d;
						}
					}

				}
			}
			for (int i = 0; i < chk.size(); i++) {
				int r = chk[i].first, c = chk[i].second;
				alive.push_back({ r,c,tmp[r][c][0],tmp[r][c][1] });
			}
			v.clear();
			v = alive;
		}
		long long res = 0;
		for (int i = 0; i < v.size(); i++) res += v[i].num;
		printf("#%d %lld\n", t, res);
	}
	return 0;
}