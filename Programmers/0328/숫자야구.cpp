#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
bool numChk[10];
int answer = 0;
bool chkStrike(string num, vector<vector<int>> baseball) {
	bool flag = false;
	for (int i = 0; i<baseball.size(); i++) {
		string chkNum = to_string(baseball[i][0]);
		int strike = 0;
		for (int j = 0; j<3; j++)
			if (num.at(j) == chkNum.at(j)) strike++;

		if (baseball[i][1] != strike) {
			flag = true;
			break;
		}
	}
	if (flag) return false;
	else return true;
}
int chkBall(string num, vector<vector<int>> baseball) {
	bool flag = false;
	for (int i = 0; i<baseball.size(); i++) {
		string chkNum = to_string(baseball[i][0]);
		int ball = 0;
		for (int a = 0; a<3; a++)
			for (int b = 0; b<3; b++)
				if (chkNum.at(a) == num.at(b) && a != b) ball++;

		if (baseball[i][2] != ball) {
			flag = true;
			break;
		}
	}
	if (flag) return false;
	else return true;
}
void dfs(string curNum, vector<vector<int>> baseball) {
	if (curNum.length() == 3) {
		if (chkStrike(curNum, baseball) && chkBall(curNum, baseball)) answer++;
		return;
	}
	for (char i = '1'; i <= '9'; i++) {
		if (!numChk[i - '0']) {
			numChk[i - '0'] = true;
			dfs(curNum + i, baseball);
			numChk[i - '0'] = false;
		}
	}
}
int solution(vector<vector<int>> baseball) {
	answer = 0;
	memset(numChk, 0, sizeof(numChk));
	for (char i = '1'; i <= '9'; i++) {
		numChk[i - '0'] = true;
		string n(1, i);
		dfs(n, baseball);
		numChk[i - '0'] = false;
	}
	return answer;
}