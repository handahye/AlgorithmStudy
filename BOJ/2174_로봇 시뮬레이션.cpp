#include <iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct st{
	int r, c, dir;
};
int A, B, N, M;
int map[101][101];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
vector<st> robot;
int turnLeft(int d) {
	if (d == 0) return 3;
	else if (d == 1) return 2;
	else if (d == 2) return 0;
	else if (d == 3) return 1;
}
int turnRight(int d) {
	if (d == 0) return 2;
	else if (d == 1) return 3;
	else if (d == 2) return 1;
	else if (d == 3) return 0;
}
int main() {
	scanf("%d%d%d%d", &A, &B, &N, &M);
	int idx = 0;
	for (int i = 0; i < N; i++) {
		int r, c;
		char d;
		cin >> c >> r >> d;
		idx++;
		r = B + 1 - r;
		map[r][c] = idx;
		if (d == 'W') robot.push_back({ r,c,1 });
		else if (d == 'E') robot.push_back({ r,c,0 });
		else if (d == 'S') robot.push_back({ r,c,2 });
		else if (d == 'N') robot.push_back({ r,c,3 });
	}
	bool error = false;
	for (int i = 0; i < M; i++) {
		int num, cnt;
		char comm;
		cin >> num >> comm >> cnt;
		int r = robot[num - 1].r, c = robot[num - 1].c;
		int d = robot[num - 1].dir;
		if (comm == 'L') {
			for (int j = 0; j < cnt; j++) d = turnLeft(d);
			robot[num - 1].dir = d;
		}
		else if (comm == 'R') {
			for (int j = 0; j < cnt; j++) d = turnRight(d);
			robot[num - 1].dir = d;
		}
		else if (comm == 'F') {
			map[r][c] = 0;
			for (int j = 0; j < cnt; j++) {
				int nr = r + dr[d], nc = c + dc[d];
				if (nr<1 || nc<1 || nr>B || nc>A) {
					error = true;
					printf("Robot %d crashes into the wall", num);
					break;
				}
				else if (map[nr][nc] != 0) {
					error = true;
					printf("Robot %d crashes into robot %d", num,map[nr][nc]);
					break;
				}
				r = nr, c = nc;
			}
			map[r][c] = num;
			robot[num - 1].r = r, robot[num - 1].c = c;
		}
		if (error) break;
	}
	if (!error) printf("OK");
	return 0;
}