#include <iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;
/*
D4_추억의 2048게임
*/
int main() {
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int map[21][21] = { 0, };
		int res[21][21] = { 0, };
		queue<int> q;
		string str;
		int i, j;
		cin >> N;
		cin>> str;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		if (str == "up") {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (map[j][i] != 0) q.push(map[j][i]); //0이 아닌 숫자를 모두 큐에 담음
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
							res[idx][i] = cur * 2; 
							chk = true;
						}
					}
					if(!chk) res[idx][i] = cur;
					idx++;
				}
			}
		}
		else if (str == "down") {
			for (i = 0; i < N; i++) {
				for (j = N-1; j >= 0; j--) {
					if (map[j][i] != 0)q.push(map[j][i]);
				}
				int idx = N-1;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					bool chk = false;
					if (!q.empty()) {
						int next = q.front();
						if (next == cur) { //현재 숫자와 다음 숫자가 같은 경우
							q.pop();
							res[idx][i] = cur * 2;
							chk = true;
						}
					}
					if(!chk) res[idx][i] = cur; //다른 경우는 그냥 현재 숫자 넣음
					idx--;
				}
			}

		}
		else if (str == "right") {
			for (int i = 0; i < N; i++) {
				for (int j = N - 1; j >= 0; j--) {
					if (map[i][j] != 0) q.push(map[i][j]);
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
							res[i][idx] = cur * 2;
							chk = true;
						}
					}
					if(!chk) res[i][idx] = cur;
					idx--;
				}
			}
		}
		else if (str == "left") {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if(map[i][j]!=0) q.push(map[i][j]);
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
							res[i][idx] = cur * 2;
							chk = true;
						}
					}
					if(!chk) res[i][idx] = cur;
					idx++;
				}
			}
		}
		printf("#%d\n", t);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", res[i][j]);
			}
			printf("\n");
		}
	
	}

	return 0;
}