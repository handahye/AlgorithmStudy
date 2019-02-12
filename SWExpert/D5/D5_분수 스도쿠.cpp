#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
/*
D5_분수 스도쿠
*/
int map[2][6][6];
bool chk[6][6];
bool row[6][10], col[6][10], box[6][10];
bool End; 
int boxNum[6][6];
bool numChk(int r, int c, int b, int num) {
	bool res;
	if (row[r][num] || col[c][num] || box[b][num]) res = true;
	else res = false;
	return res;
}
void dfs(int flag, int r, int c) {
	if (r == 6) {
		End = true;
		return;
	}
	int nr=r, nc=c;
	if (nc >=5) nr+=1, nc = 0;
	else nc+=1;
	
	if (map[flag][r][c] == 0) {
		if (flag == 0) { //분자 or 그냥 숫자
			for (int num = 1; num <= 9; num++) {
				if (numChk(r, c, boxNum[r][c],num)) continue; //행, 렬, 박스안에 이미 같은 번호가 있는 경우
				if (chk[r][c])  //분자인 경우 -> 이미 분모에 숫자가 있는데 그 숫자가 분자보다 작은 경우는 안됨
					if (map[1][r][c]>0 && map[1][r][c] < num) continue;
				
				map[flag][r][c] = num;
				row[r][num] = col[c][num] = box[boxNum[r][c]][num] = true;

				if (chk[r][c]) dfs(1, r, c); //분자라면 분모를 체크해야됨
				else dfs(0, nr, nc); //그냥 숫자면 다음으로 넘어가면 됨
				
				if (End) return;

				map[flag][r][c] = 0;
				row[r][num] = col[c][num] = box[boxNum[r][c]][num] = false;
			}
		}
		else {//분모일 경우에는 분자보다 숫자가 커야되니까 
			for (int num = map[0][r][c] + 1; num <= 9; num++) {
				if (numChk(r, c, boxNum[r][c], num)) continue; //행, 렬, 박스안에 이미 같은 번호가 있는 경우
				map[flag][r][c] = num;
				row[r][num] = col[c][num] = box[boxNum[r][c]][num] = true;
				dfs(0, nr, nc); 

				if (End) return;

				map[flag][r][c] = 0;
				row[r][num] = col[c][num] = box[boxNum[r][c]][num] = false;
			}
		}
	}
	else { //이미 숫자가 존재하는 경우
		if (flag == 0 && chk[r][c]) dfs(1, r, c); //분자인 경우는 분모로
		else dfs(0, nr, nc); //그냥 숫자 or 분모인 경우엔 다음으로
	}
}
void init() {
	End = false;
	memset(map, 0, sizeof(map));
	memset(chk, false, sizeof(chk));
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(row));
	memset(box, false, sizeof(row));
	//박스번호
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j >= 0 && j <= 2) {
				if (i <= 1) boxNum[i][j] = 0;
				else if (i <= 3) boxNum[i][j] = 2;
				else if (i <= 5) boxNum[i][j] = 4;
			}
			else if (j >= 3 && j <= 5) {
				if (i <= 1) boxNum[i][j] = 1;
				else if (i <= 3) boxNum[i][j] = 3;
				else if (i <= 5) boxNum[i][j] = 5;
			}

		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				char c[4];
				cin >> c;
				if (c[0] == '-') map[0][i][j] = 0;
				else {
					map[0][i][j] = c[0] - '0';
					int b = boxNum[i][j];
					row[i][map[0][i][j]] = col[j][map[0][i][j]] = box[b][map[0][i][j]] = true;
				}
				if (c[1] == NULL) continue;
				if (c[1] == '/'){
					chk[i][j] = 1;
					if (c[2] == '-') map[1][i][j] = 0;
					else {
						map[1][i][j] = c[2] - '0';
						int b = boxNum[i][j];
						row[i][map[1][i][j]] = col[j][map[1][i][j]] = box[b][map[1][i][j]] = true;
					}
				}
				
			}
		}

		dfs(0, 0, 0);
		cout << "#" << t << endl;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				cout << map[0][i][j];
				if (chk[i][j]) 
					cout << "/" << map[1][i][j];
				cout << " ";
			}
			cout << endl;
		}
	}

	return 0;
}