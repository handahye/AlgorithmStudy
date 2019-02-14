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
int map[2][6][6]; //map[0][][]는 분자 or 그냥 숫자를 가르킴, map[1][][]는 분모를 가르킴
bool chk[6][6]; //분수인지 아닌지 체크하기 위해서
bool row[6][10], col[6][10], box[6][10]; //같은 행, 같은 열, 같은 박스에 "같은 숫자"가 중복되는지 체크하기 위해서
bool End; 
int boxNum[6][6]; //박스의 넘버를 저장해 놓은 array
bool numChk(int r, int c, int b, int num) { //현재 r, c, b에 num이 있는지 체크하기 위해서 
	bool res;
	if (row[r][num] || col[c][num] || box[b][num]) res = true;
	else res = false;
	return res;
}
void dfs(int flag, int r, int c) { //flag가 0이면 분자 or 그냥 숫자를 체크하고, 1이면 분모를 체크
	if (r == 6) { //행이 6이 되면 다 체크한거니까 끝냄
		End = true;
		return;
	}
	int nr=r, nc=c;
	if (c >=5) nr+=1, nc = 0; //현재 열이 5면 다음에 체크해야 되는건 다음 행의 첫번째 열 
	else nc+=1;//현재 열이 5보다 작으면 같은 행의 다음 열을 체크하면 됨
	
	if (map[flag][r][c] == 0) { //map에 숫자가 없어서 채워 넣어야 하는 경우 
		if (flag == 0) { //분자 or 그냥 숫자
			for (int num = 1; num <= 9; num++) {//채울 숫자는 1~9까지 가능
				if (numChk(r, c, boxNum[r][c],num)) continue; //행, 렬, 박스안에 이미 같은 번호가 있는 경우
				if (chk[r][c])  //분수인 경우: 분자 -> 이미 분모에 숫자가 있는데 분자보다 작은 경우는 안됨
					if (map[1][r][c]>0 && map[1][r][c] < num) continue;
				
				map[flag][r][c] = num; //현재 선택한 num을 map에 넣어줌
				row[r][num] = col[c][num] = box[boxNum[r][c]][num] = true; //행, 렬, 박스 번호에도 체크해줌

				if (chk[r][c]) dfs(1, r, c); //분수인 경우 분자를 체크한거니까 다음으로 같은 행과 열의 분모를 체크해야됨
				else dfs(0, nr, nc); //그냥 숫자면 다음으로 넘어가면 됨
				
				if (End) return; 

				map[flag][r][c] = 0; //선택했던 num이 안되는 경우는 다시 map을 0으로 바꿔줌
				row[r][num] = col[c][num] = box[boxNum[r][c]][num] = false;//행, 렬, 박스 번호도 다시 false로 바꿔줌
			}
		}
		else {//분모일 경우에는 분자보다 숫자가 커야되니까 
			for (int num = map[0][r][c] + 1; num <= 9; num++) {//분자+1 ~ 9까지
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
	else { //이미 숫자가 존재해서 채워넣지 않아도 되는 경우
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
	//각 행과 열이 가르키는 박스 번호를 boxNum에 저장해 놓음
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
				if (c[0] == '-') map[0][i][j] = 0;//값이 없는거니까 0으로 저장
				else {
					map[0][i][j] = c[0] - '0'; //값이 있으면 
					int b = boxNum[i][j];
					row[i][map[0][i][j]] = col[j][map[0][i][j]] = box[b][map[0][i][j]] = true; //그 숫자를 현재 가르키는 행, 렬, 박스 번호에 체크함
				}
				if (c[1] == NULL) continue; 
				if (c[1] == '/'){//분수라면
					chk[i][j] = 1; //chk 어레이에 현재 행, 열이 분수인걸 체크함
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