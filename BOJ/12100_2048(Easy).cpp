#include <iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
/*
BOJ_12100_2048(Easy)
*/
int N;
int map[21][21] = { 0, };
queue<int> q;
int maxN = -987654321;
void copyMap(int a[][21], int b[][21]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			a[i][j] = b[i][j];
}
void arrange(int dir) {
	int i, j;
	if (dir == 0) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (map[j][i] != 0) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}//0이 아닌 숫자를 모두 큐에 담음
			}
			int idx = 0;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				bool chk = false;
				if (!q.empty()) {
					int next = q.front();
					if (next == cur) { //현재 숫자와 다음 숫자가 같은 경우
						q.pop();
						map[idx][i] = cur * 2;
						chk = true;
					}
				}
				if (!chk) map[idx][i] = cur;
				idx++;
			}
		}
	}
	else if (dir == 1) {
		for (i = 0; i < N; i++) {
			for (j = N - 1; j >= 0; j--) {
				if (map[j][i] != 0)
				{
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			}
			int idx = N - 1;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				bool chk = false;
				if (!q.empty()) {
					int next = q.front();
					if (next == cur) { //현재 숫자와 다음 숫자가 같은 경우
						q.pop();
						map[idx][i] = cur * 2;
						chk = true;
					}
				}
				if (!chk) map[idx][i] = cur; //다른 경우는 그냥 현재 숫자 넣음
				idx--;
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			int idx = N - 1;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				bool chk = false;
				if (!q.empty()) {
					int next = q.front();
					if (next == cur) { //현재 숫자와 다음 숫자가 같은 경우
						q.pop();
						map[i][idx] = cur * 2;
						chk = true;
					}
				}
				if (!chk) map[i][idx] = cur;
				idx--;
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			}
			int idx = 0;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				bool chk = false;
				if (!q.empty()) {
					int next = q.front();
					if (next == cur) { //현재 숫자와 다음 숫자가 같은 경우
						q.pop();
						map[i][idx] = cur * 2;
						chk = true;
					}
				}
				if (!chk) map[i][idx] = cur;
				idx++;
			}
		}
	}
}
void dfs(int cnt, int dir) {
	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxN = max(maxN, map[i][j]);
			}
		}
		return;
	}
	int tmp[21][21];
	for (int d = 0; d < 4; d++) {
		copyMap(tmp, map);
		arrange(d);
		dfs(cnt + 1, d);
		copyMap(map, tmp);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	dfs(0, 0);
	printf("%d", maxN);
	return 0;
}