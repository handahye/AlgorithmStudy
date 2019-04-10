#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int R, C, N;
bool visit[201][201] = { false, };
int map[201][201];
vector<pair<int, int>> v;
int main() {
	scanf("%d%d%d", &R, &C, &N);
	int num = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			if (c == '.') map[i][j] = 0;
			else {
				map[i][j] = 1;
				v.push_back({ i,j });
				visit[i][j] = true;
			}
		}
	}
	if (N % 2 == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C;j++) {
				printf("O");
			}
			printf("\n");
		}
		return 0;
	}
	int time = 3;
	while (time <= N) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C;j++) {
				map[i][j] = 1;
			}
		}
		for (int i = 0; i < v.size(); i++) {
			int r = v[i].first, c = v[i].second;
			map[r][c] = 0;
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr >= 0 && nc >= 0 && nr < R && nc < C) {
					if (!visit[nr][nc]) {
						map[nr][nc] = 0;
					}
				}
			}
		}
		v.clear();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 1) 
					v.push_back({ i,j });
			}
		}
		time += 2;
	}

	for (int i = 0; i < R; i++) {
		for(int j = 0; j < C;j++){
			if (map[i][j] == 1) printf("O");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}