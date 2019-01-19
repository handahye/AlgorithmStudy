#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
bool numChk[10];
int answer = 0;
bool chkStrike(int n, vector<vector<int>> baseball) {
	bool flag = false;
	string num = to_string(n);
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
int chkBall(int n, vector<vector<int>> baseball) {
	bool flag = false;
	string num = to_string(n);
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
void dfs(int curNum, vector<vector<int>> baseball) {
	string num = to_string(curNum);
	if (num.length() == 3) {
		int n = atoi(num.c_str());
		if (chkStrike(n, baseball) && chkBall(n, baseball)) answer++;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!numChk[i]) {
			numChk[i] = true;
			string nextNum(1, i + '0');
			string strTmp = to_string(curNum) + nextNum;
			int intTmp = atoi(strTmp.c_str());
			dfs(intTmp, baseball);
			numChk[i] = false;
		}
	}
}
int solution(vector<vector<int>> baseball) {
	answer = 0;
	memset(numChk, 0, sizeof(numChk));
	for (int i = 1; i <= 9; i++) {
		numChk[i] = true;
		dfs(i, baseball);
		numChk[i] = false;
	}
	return answer;
}